import 'package:flutter/material.dart';
import 'package:speech_to_text/speech_recognition_result.dart';
import 'package:speech_to_text/speech_to_text.dart';
import 'package:roslibdart/roslibdart.dart';
import 'dart:async';
import 'package:flutter_tts/flutter_tts.dart';

class VoiceAssistant extends StatefulWidget {
  dynamic ros, updateConnectionStatus;

  VoiceAssistant({super.key, required this.ros, required this.updateConnectionStatus});

  @override
  State<VoiceAssistant> createState() => _VoiceAssistantState();
}

class _VoiceAssistantState extends State<VoiceAssistant> {
  final SpeechToText _speechToText = SpeechToText();
  final TextEditingController _textController = TextEditingController();

  bool _speechEnabled = false;
  String _lastWords = '';
  List<Map<String, String>> conversation = [];

  @override
  void initState() {
    super.initState();
    _initSpeech();
  }

  void _initSpeech() async {
    _speechEnabled = await _speechToText.initialize();
    setState(() {});
  }
  Future<void> speak(String text) async {
    FlutterTts flutterTts = FlutterTts();
    await flutterTts.setSharedInstance(true);
    await flutterTts.setIosAudioCategory(IosTextToSpeechAudioCategory.playback,
      [
        IosTextToSpeechAudioCategoryOptions.allowBluetooth,
        IosTextToSpeechAudioCategoryOptions.allowBluetoothA2DP,
        IosTextToSpeechAudioCategoryOptions.mixWithOthers,
        IosTextToSpeechAudioCategoryOptions.defaultToSpeaker
      ],
      IosTextToSpeechAudioMode.defaultMode
    );

    await flutterTts.setLanguage('en-US');
    await flutterTts.setPitch(1.0);
    await flutterTts.speak(text);
  }

  void _startListening() async {
    _lastWords = "";

    if(_speechToText.isNotListening){
      await _speechToText.listen(onResult: _onSpeechResult);
      conversation.add({"actor": "user", "sentence": ""});
      setState(() {});
    }
  }

  void _stopListening() async {
    await _speechToText.stop();
    setState(() {});
    _contactLM();
  }

  void _onSpeechResult(SpeechRecognitionResult result) {
    setState(() {
      _lastWords = result.recognizedWords;
    });

    if (conversation[conversation.length - 1]["actor"]!="dash") conversation[conversation.length - 1]["sentence"] = _lastWords;
    if (_speechToText.isNotListening && conversation[conversation.length - 1]["actor"]!="dash") {
      conversation.add({"actor": "dash", "sentence": "..."});
      // _contactLM();
    }
  }

  Future<void> _contactLM() async {
    final service = Service(name: 'chat', ros: widget.ros, type: "robot_interfaces/LMChat");
    Map<String, dynamic> request = {"in_msg": _lastWords};
    _lastWords = "";

    print(conversation[conversation.length - 1]);
    try {
      final response = await service.call(request);
      conversation[conversation.length - 1]["sentence"] = response["out_msg"];
      speak(response["out_msg"]);
    } finally {
      setState(() {});
    }
  }

  void _sendText() {
    String text = _textController.text.trim();
    if (text.isNotEmpty) {
      setState(() {
        conversation.add({"actor": "user", "sentence": text});
        conversation.add({"actor": "dash", "sentence": "..."});
      });
      _lastWords = text;
      _textController.clear();
      _contactLM();
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        toolbarHeight: 60,
        title: const Text('Voice Assistant', style: TextStyle(fontFamily: 'Poppins', fontWeight: FontWeight.bold)),
        centerTitle: true,
        backgroundColor: Colors.transparent,
      ),
      backgroundColor: Colors.black,
      body: SingleChildScrollView( // Wrap your existing Column widget with SingleChildScrollView
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Container(
              height: MediaQuery.of(context).size.height - 220,
              width: MediaQuery.of(context).size.width,
              padding: const EdgeInsets.fromLTRB(10, 10, 10, 10),
              color: Colors.black,
              child: ListView.builder(
                  itemCount: conversation.length,
                  itemBuilder: (context, index) {
                    String? actor = conversation[index]['actor'];
                    String? sentence = conversation[index]['sentence'];

                    return Align(
                      alignment: actor == 'dash'? Alignment.topLeft : Alignment.topRight,
                      child: Container(
                        margin: const EdgeInsets.symmetric(vertical: 5.0),
                        padding: const EdgeInsets.all(10.0),
                        constraints: const BoxConstraints(
                          maxWidth: 300,
                        ),
                        decoration: BoxDecoration(
                          color: actor == 'dash'? Colors.green : Colors.blueAccent,
                          borderRadius: BorderRadius.circular(8.0),
                        ),
                        child: Text(
                          sentence!,
                          style: const TextStyle(fontSize: 16.0, color: Colors.white),
                        ),
                      ),
                    );
                  }),
            ),
            const SizedBox(height: 10),
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 10.0),
              child: Row(
                children: [
                  Expanded(
                    child: TextField(
                      controller: _textController,
                      decoration: InputDecoration(
                        hintText: 'Type a message',
                        fillColor: Colors.white,
                        filled: true,
                        border: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(30.0),
                          borderSide: BorderSide.none,
                        ),
                      ),
                      style: const TextStyle(color: Colors.black),
                    ),
                  ),
                  const SizedBox(width: 10),
                  ElevatedButton(
                    onPressed: _sendText,
                    style: ElevatedButton.styleFrom(
                      shape: const CircleBorder(),
                      padding: const EdgeInsets.all(15.0),
                      backgroundColor: Colors.blueAccent,
                    ),
                    child: const Icon(Icons.send, color: Colors.white),
                  ),
                  const SizedBox(width: 10),
                  ElevatedButton(
                    onPressed: _speechEnabled? (_speechToText.isNotListening? _startListening : _stopListening) : null,
                    style: ElevatedButton.styleFrom(
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(40.0),
                        side: const BorderSide(color: Colors.white70, width: 3),
                      ),
                      minimumSize: const Size(45, 55),
                      backgroundColor: _speechToText.isNotListening? Colors.transparent : Colors.white,
                    ),
                    child: Icon(
                      _speechToText.isNotListening? Icons.mic_off : Icons.mic,
                      color: _speechEnabled? (_speechToText.isNotListening? Colors.white : Colors.black) : Colors.red,
                    ),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
