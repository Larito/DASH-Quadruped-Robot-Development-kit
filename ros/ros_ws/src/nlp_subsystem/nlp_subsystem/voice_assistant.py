#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_interfaces.srv import LMChat
from geometry_msgs.msg import Twist

import requests
import google.generativeai as genai
from transformers import BertTokenizer, BertForSequenceClassification
import torch

class LanguageModelService(Node):
    def __init__(self):
        super().__init__("language_model_Server")
        self.server_ = self.create_service(LMChat, "chat", self.callback_chat)
        self.conversation_history = []

        self.twist_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

        # genai.configure(api_key="AIzaSyC6v8KAvC0WBfF7GiTF3jP50cP_zfCW6oY")
        # generation_config = {
        #     "temperature": 0.9,
        #     "top_p": 1,
        #     "top_k": 1,
        #     "max_output_tokens": 2048,
        # }
        # safety_settings = [
        #     {
        #         "category": "HARM_CATEGORY_HARASSMENT",
        #         "threshold": "BLOCK_MEDIUM_AND_ABOVE"
        #     },
        #     {
        #         "category": "HARM_CATEGORY_HATE_SPEECH",
        #         "threshold": "BLOCK_MEDIUM_AND_ABOVE"
        #     },
        #     {
        #         "category": "HARM_CATEGORY_SEXUALLY_EXPLICIT",
        #         "threshold": "BLOCK_MEDIUM_AND_ABOVE"
        #     },
        #     {
        #         "category": "HARM_CATEGORY_DANGEROUS_CONTENT",
        #         "threshold": "BLOCK_MEDIUM_AND_ABOVE"
        #     },
        # ]
        # gemini = genai.GenerativeModel(model_name="gemini-1.0-pro",generation_config=generation_config,safety_settings=safety_settings)
        # self.convo = gemini.start_chat(history=self.conversation_history)

        self.id2label = {0: "Chat", 1: "Forward", 2: "Backward", 3: "Left", 4: "Right"}
        self.label2id = {"Chat": 0, "Forward": 1, "Backward": 2, "Left": 3, "Right": 4 }
        self.bert_model = BertForSequenceClassification.from_pretrained('/home/dash/Desktop/ros_ws/src/nlp_subsystem/models')
        self.bert_tokenizer = BertTokenizer.from_pretrained('/home/dash/Desktop/ros_ws/src/nlp_subsystem/models/tokenizer')

        self.get_logger().info("LM is online. LM as in language model:'(")

    def callback_chat(self, request, response):
        sentences = [request.in_msg]
        predict_classes = self.predict_class(sentences)
        predicted_label = self.id2label[predict_classes[0]]

        try:
            if predicted_label != "Chat":
                response.out_msg = f"Sure! Moving {predicted_label}"

                twist_msg = Twist()
                if predicted_label == "Forward":
                    twist_msg.linear.x = 0.5 # Forward
                    twist_msg.angular.z = 0.0
                elif predicted_label == "Backward":
                    twist_msg.linear.x = -0.5 # Backward
                    twist_msg.angular.z = 0.0
                elif predicted_label == "Left":
                    twist_msg.linear.x = 0.0
                    twist_msg.angular.z = 0.5 # Left
                elif predicted_label == "Right":
                    twist_msg.linear.x = 0.0
                    twist_msg.angular.z = -0.5 # Right

                self.twist_publisher.publish(twist_msg)
                self.get_logger().info(predicted_label)
            else:
                # self.convo.send_message(request.in_msg)
                # response.out_msg = self.convo.last.text

                request.in_msg = request.in_msg + ". Keep the response very short."
                url = 'http://172.20.10.9:4000/prompt' 
                llm_res = requests.post(url, data={'prompt': request.in_msg})
                response.out_msg = llm_res.text

                self.update_conversation_history(request.in_msg)
                self.update_conversation_history(response.out_msg)

            self.get_logger().info("LM Responded: " + str(response.out_msg).replace("\n", " "))

            # TODO: publish to speaker node
        except Exception as e:
            response.out_msg = "There was a problem on my side. Please try again."
            self.get_logger().info(str(e))

        return response

    def update_conversation_history(self, message):
        self.conversation_history.append(message)

    def predict_class(self, sentences):
        inputs = self.bert_tokenizer(sentences, truncation=True, padding=True, return_tensors='pt')
        outputs = self.bert_model(**inputs)
        logits = outputs.logits
        probabilities = torch.nn.functional.softmax(logits, dim=1)
        predicted_class = torch.argmax(probabilities, dim=1).tolist()
        
        confidences = [max(p) for p in probabilities]
        
        for i in range(len(predicted_class)):
            if confidences[i].item() < 0.95: predicted_class[i] = self.label2id["Chat"]
            
        return predicted_class

def main(args=None):
    rclpy.init(args=args)

    node = LanguageModelService()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()