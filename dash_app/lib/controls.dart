import 'package:flutter/material.dart';
import 'package:roslibdart/roslibdart.dart';
import 'dart:async';
import 'dart:convert';
import 'dart:io';
import 'package:path_provider/path_provider.dart';
import 'dart:math';

class Controls extends StatefulWidget {
  dynamic ros, updateConnectionStatus;

  Controls({super.key, required this.ros, required this.updateConnectionStatus});

  @override
  State<Controls> createState() => _ControlsState();
}

class _ControlsState extends State<Controls> {
  bool gestureControl = false;
  double velocity = 0.5, angle = 0;

  Future<void> publishTwist(double linearX, double angularZ) async {
    dynamic chatter = Topic(ros: widget.ros, name: '/app_cmd_vel', type: "std_msgs/String", reconnectOnClose: true, queueLength: 10, queueSize: 10);
    Map<String, dynamic> json = {"data": "linearX:$linearX|angularZ:$angularZ"};
    await chatter.publish(json);
  }

  Future<void> _toggleGestureControl(bool toggle) async {
    final service = Service(name: 'toggle_gesture_control', ros: widget.ros, type: "std_srvs/SetBool");
    Map<String, dynamic> request = {"data": toggle};

    final timer = Timer(const Duration(seconds: 7), () {
      widget.updateConnectionStatus(false);
      Navigator.pop(context);
    });

    try {
      final response = await service.call(request);
      print(response);
    } finally {
      timer.cancel();
      setState(() {});
    }
  }

  Future<void> saveImage(String base64String) async {
    try {
      final bytes = base64Decode(base64String);
      final directory = await getApplicationDocumentsDirectory();

      final random = Random();
      final randomNumber = random.nextInt(90000) + 10000; // Generates a number between 10000 and 99999

      final filePath = '${directory.path}/captured_image_$randomNumber.jpg';

      final file = File(filePath);
      await file.writeAsBytes(bytes);

      print('Image saved to $filePath');
    } catch (e) {
      print('Error saving image: $e');
    }
  }

  List<Widget> _gamePadControls(){
    List<Widget> res = <Widget>[
      const SizedBox(height: 5,),
      const Text("You are in Manual Control Mode", style: TextStyle(color: Colors.red, fontFamily: "Poppins")),
      const SizedBox(height: 70,),

      // const Divider(color: Colors.grey, height: 40,),
      Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [
          Text('Velocity: $velocity m/s', style: const TextStyle(fontFamily: 'Poppins', color: Colors.white, fontSize: 20)),
          Text('Angle: $angle deg', style: const TextStyle(fontFamily: 'Poppins', color: Colors.white, fontSize: 20)),
        ],
      ),
      // const Divider(color: Colors.grey, height: 40,),
      const SizedBox(height: 50,),
      Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          TextButton(
            onPressed: () {publishTwist(0.5, 0);},
            child: const Icon(Icons.arrow_circle_up, size:55, color: Colors.white70),
          ),
        ],
      ),
      // const SizedBox(height: 10,),
      Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          TextButton(
            onPressed: () {publishTwist(0, 0.5);},
            child: const Icon(Icons.arrow_circle_left_outlined, size:55, color: Colors.white70),
          ),
          // const SizedBox(width: 10,),
          TextButton(
            onPressed: () {publishTwist(0, 0);},
            child: const Icon(Icons.stop, size:55, color: Colors.white70),
          ),
          // const SizedBox(width: 10,),
          TextButton(
            onPressed: () {publishTwist(0, -0.5);},
            child: const Icon(Icons.arrow_circle_right_outlined, size:55, color: Colors.white70),
          ),
        ],
      ),
      Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          TextButton(
            onPressed: () {publishTwist(-0.5, 0);},
            child: const Icon(Icons.arrow_circle_down, size:55, color: Colors.white70),
          ),
        ],
      ),

      SizedBox(height: 50,),

      ElevatedButton(
          onPressed: () async {
            final service = Service(name: 'image_capture', ros: widget.ros, type: "robot_interfaces/ImageCapture");
            Map<String, dynamic> request = {"command": "capture"};
            final response = await service.call(request);
            final base64Image = response["image_base64"];
            await saveImage(base64Image);
          },
          style: ElevatedButton.styleFrom(
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(7),
              side: const BorderSide(color: Colors.white70),
            ),
            backgroundColor: Colors.transparent,
            elevation: 2,
            minimumSize: const Size(305, 50),
          ),
          child: const Text(
            "Capture",
            style: TextStyle(
              color: Colors.white,
              fontSize: 17,
              fontFamily: "Poppins",
            ),
          )
      )

    ];

    return res;
  }

  List<Widget> _gestureControlInstructions(){
    List<Widget> res = <Widget>[
      const Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          SizedBox(height: 5,),
          Text("You are in Gesture Control Mode", style: TextStyle(color: Colors.red, fontFamily: "Poppins")),
          SizedBox(height: 70,),

          Icon(Icons.arrow_circle_up, size:40, color: Colors.white70),
          SizedBox(height: 5,),
          Text("Make the rock n' roll hand sign", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),

          SizedBox(height: 20,),
          Icon(Icons.arrow_circle_down, size:40, color: Colors.white70),
          SizedBox(height: 5,),
          Text("Close your fist", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),

          SizedBox(height: 20,),
          Icon(Icons.arrow_circle_right_outlined, size:40, color: Colors.white70),
          SizedBox(height: 5,),
          Text("Make a peace sign", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),

          SizedBox(height: 20,),
          Icon(Icons.arrow_circle_left_outlined, size:40, color: Colors.white70),
          SizedBox(height: 5,),
          Text("Hold up your index finger", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),

          SizedBox(height: 20,),
          Icon(Icons.stop, size:40, color: Colors.white70),
          SizedBox(height: 5,),
          Text("Hold up your palm", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),

          // SizedBox(height: 20,),
          // Icon(Icons.stop, size:40, color: Colors.white70),
          // SizedBox(height: 5,),
          // Text("Thumbs up sign", style: TextStyle(color: Colors.blue, fontFamily: "Poppins")),
        ],
      )
    ];

    return res;
  }

  @override
  Widget build(BuildContext context) {
    List<Widget> controls = gestureControl?_gestureControlInstructions():_gamePadControls();
    List<Widget> body = [
      Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          TextButton(
            child: Icon(gestureControl?Icons.gamepad:Icons.front_hand, size:30, color: Colors.white70),
            onPressed: () {
              setState(() {
                gestureControl = !gestureControl;
              });
              _toggleGestureControl(gestureControl);
            },
          ),
          TextButton(
            child: const Icon(Icons.help_outline_outlined, size:30, color: Colors.white70),
            onPressed: () {},
          ),
        ],
      ),
      const SizedBox(height: 10,),
    ];

    for(int i=0;i<controls.length;i++){
      body.add(controls[i]);
    }
    return Scaffold(
        appBar: AppBar(
          toolbarHeight: 50,
          title: const Text('DASH Controls', style: TextStyle(fontFamily: 'Poppins', fontWeight: FontWeight.bold)),
          centerTitle: true,
          backgroundColor: Colors.transparent,
        ),
        backgroundColor: Colors.black,
        body: Container(
          width: MediaQuery.of(context).size.width,
          padding: const EdgeInsets.fromLTRB(15, 0, 15, 15),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.center,
            children: body
          )
        )
    );
  }
}
