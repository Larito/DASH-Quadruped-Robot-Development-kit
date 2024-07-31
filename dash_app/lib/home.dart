import 'package:flutter/material.dart';
import 'package:dash/settings.dart';
import 'package:dash/controls.dart';
import 'package:dash/voice_assistant.dart';
import 'package:roslibdart/roslibdart.dart';
import 'dart:async';

class Home extends StatefulWidget {
  dynamic ros, updateConnectionStatus;

  Home({super.key, required this.ros, required this.updateConnectionStatus});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  int batteryState = 6;
  int minutesRemaining = 45;
  int currentMode = 1;

  Map<int, String> numToModeMapping = {
    1: "Idle",
    2: "Navigating",
    3: "Mapping",
  };

  IconData _getBatteryIcon(){
    if(batteryState == 1) return Icons.battery_1_bar;
    if(batteryState == 2) return Icons.battery_2_bar;
    if(batteryState == 3) return Icons.battery_3_bar;
    if(batteryState == 4) return Icons.battery_4_bar;
    if(batteryState == 5) return Icons.battery_5_bar;
    if(batteryState == 6) return Icons.battery_6_bar;
    return Icons.battery_full;
  }

  Color _getBatteryColor(){
    if([1,2,3].contains(batteryState)) return Colors.red;
    if([4,5].contains(batteryState)) return Colors.yellow;
    return Colors.green;
  }

  Widget _statusCard(){
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Container(
          padding: const EdgeInsets.fromLTRB(20, 20, 20, 20),
          decoration: const BoxDecoration(
              gradient: LinearGradient(
                begin: Alignment.topCenter,
                end: Alignment.bottomCenter,
                colors: [
                  Colors.blueGrey,
                  Colors.black,
                ],
              )
          ),
          width: MediaQuery.of(context).size.width,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              const SizedBox(height: 40,),
              Text("Current Mode: ${numToModeMapping[currentMode]!}", style: TextStyle(color: Colors.white, fontSize: 17, fontWeight: FontWeight.bold,fontFamily: "Poppins"),),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  RotatedBox(
                    quarterTurns: 1,
                    child: Icon(_getBatteryIcon(), size:75, color: _getBatteryColor()),
                  ),
                  const SizedBox(width: 5,),
                  Text("$minutesRemaining Mins", style: const TextStyle(color: Colors.white, fontSize: 23, fontFamily: "Poppins"),)
                ],
              ),
              const SizedBox(height: 10,),
              const Image(
                image: AssetImage("images/DASH.png"),
                height: 150,
              ),
            ],
          ),
        )
      ]
    );
  }

  Widget _getMainButtons(){
    return Container(
      width: MediaQuery.of(context).size.width,
      color: Colors.black,
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          ElevatedButton(
            onPressed: (){
              try {
                Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return VoiceAssistant(ros:widget.ros, updateConnectionStatus: widget.updateConnectionStatus,);}));
              } catch (e) {}
            },
            style: ElevatedButton.styleFrom(
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(7),
                side: const BorderSide(color: Colors.white70),
              ),
              backgroundColor: Colors.transparent,
              elevation: 2,
              minimumSize: const Size(150, 50), // Set the desired width and height
            ),
            child: const Icon(Icons.chat, size:25, color: Colors.white70),
          ),
          const SizedBox(width: 5,),
          ElevatedButton(
            onPressed: (){
              Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return Controls(ros:widget.ros, updateConnectionStatus:widget.updateConnectionStatus);}));
            },
            style: ElevatedButton.styleFrom(
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(7),
                side: const BorderSide(color: Colors.white70),
              ),
              backgroundColor: Colors.transparent,
              elevation: 2,
              minimumSize: const Size(150, 50), // Set the desired width and height
            ),
            child: const Icon(Icons.gamepad, size:25, color: Colors.white70),
          ),
        ],
      )
    );
  }

  Widget _getSecondaryButtonsOld(){
    return Container(
        width: MediaQuery.of(context).size.width,
        color: Colors.black,
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            // ElevatedButton(
            //   onPressed:(){
            //     try {
            //       Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return Controls(ros:widget.ros, updateConnectionStatus:widget.updateConnectionStatus);}));
            //     } catch (e) {}
            //   },
            //   style: ElevatedButton.styleFrom(
            //     shape: RoundedRectangleBorder(
            //       borderRadius: BorderRadius.circular(7),
            //       side: const BorderSide(color: Colors.white70),
            //     ),
            //     backgroundColor: Colors.transparent,
            //     elevation: 2,
            //     minimumSize: const Size(305, 50),
            //   ),
            //   child: const Text("Controls", style: TextStyle(color: Colors.white, fontSize: 17, fontFamily: "Poppins",),)
            // ),
            // const SizedBox(height: 10,),
            // ElevatedButton(
            //     onPressed: (){
            //       try {
            //         Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return Camera(ros:widget.ros, updateConnectionStatus:widget.updateConnectionStatus);}));
            //       } catch (e) {}
            //     },
            //     style: ElevatedButton.styleFrom(
            //       shape: RoundedRectangleBorder(
            //         borderRadius: BorderRadius.circular(7),
            //         side: const BorderSide(color: Colors.white70),
            //       ),
            //       backgroundColor: Colors.transparent,
            //       elevation: 2,
            //       minimumSize: const Size(305, 50),
            //     ),
            //     child: const Text("Camera", style: TextStyle(color: Colors.white, fontSize: 17, fontFamily: "Poppins",),)
            // ),
            const SizedBox(height: 10,),
            ElevatedButton(
                onPressed: (){
                  try {
                    Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return Settings(ros:widget.ros, updateConnectionStatus:widget.updateConnectionStatus);}));
                  } catch (e) {}
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
                child: const Text("Settings", style: TextStyle(color: Colors.white, fontSize: 17, fontFamily: "Poppins",),)
            ),
            const SizedBox(height: 10,),
            ElevatedButton(
                onPressed: (){
                  widget.updateConnectionStatus(false);
                },
                style: ElevatedButton.styleFrom(
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(7),
                    side: const BorderSide(color: Colors.redAccent),
                  ),
                  backgroundColor: Colors.transparent,
                  elevation: 2,
                  minimumSize: const Size(305, 50),
                ),
                child: const Text("Disconnect", style: TextStyle(color: Colors.redAccent, fontSize: 17, fontFamily: "Poppins",),)
            ),
          ]
      )
    );
  }

  Widget _getSecondaryButtons(){
    return Container(
        width: MediaQuery.of(context).size.width,
        color: Colors.black,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              onPressed: (){
                try {
                  Navigator.of(context).push(MaterialPageRoute(builder: (BuildContext context) {return Settings(ros:widget.ros, updateConnectionStatus:widget.updateConnectionStatus);}));
                } catch (e) {}
              },
              style: ElevatedButton.styleFrom(
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(7),
                  side: const BorderSide(color: Colors.white70),
                ),
                backgroundColor: Colors.transparent,
                elevation: 2,
                minimumSize: const Size(150, 50), // Set the desired width and height
              ),
              child: const Icon(Icons.settings, size:25, color: Colors.white70),
            ),
            const SizedBox(width: 5,),
            ElevatedButton(
              onPressed: (){
                widget.updateConnectionStatus(false);
              },
              style: ElevatedButton.styleFrom(
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(7),
                  side: const BorderSide(color: Colors.redAccent),
                ),
                backgroundColor: Colors.transparent,
                elevation: 2,
                minimumSize: const Size(150, 50), // Set the desired width and height
              ),
              child: const Icon(Icons.power_off_rounded, size:25, color: Colors.redAccent),
            ),
          ],
        )
    );
  }

  Future<void> _getRobotStatus() async {
    final service = Service(name: 'statusing', ros: widget.ros, type: "robot_interfaces/RobotStatusSrv");
    Map<String, dynamic> request = {"formality":true};

    final timer = Timer(const Duration(seconds: 7), () {
      widget.updateConnectionStatus(false);
      Navigator.pop(context);
    });

    try {
      final response = await service.call(request);
      if(batteryState!= response["battery_level"] || currentMode!=response["current_mode"]){
        setState(() {
          batteryState = response["battery_level"];
          currentMode = response["current_mode"];
        });
      }
    } finally {
      timer.cancel();
    }
  }

  @override
  Widget build(BuildContext context) {
    _getRobotStatus();

    return Scaffold(
      backgroundColor: Colors.black,
      body: Column(
        children: <Widget>[
          _statusCard(),
          const SizedBox(height: 20,),
          _getMainButtons(),
          const SizedBox(height: 10),
          _getSecondaryButtons()
        ],
      )
    );
  }
}
