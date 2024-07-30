import 'package:flutter/material.dart';
import 'package:dash/home.dart';
import 'package:roslibdart/roslibdart.dart';

void main() => runApp(const MyApp());

class Main extends StatefulWidget {
  const Main({super.key});

  @override
  State<Main> createState() => _MainState();
}

class _MainState extends State<Main> {
  bool connectionStatus = false;
  String connectionInformation = "";

  // final TextEditingController _ipController = TextEditingController(text: '192.168.8.121:9091');
  final TextEditingController _ipController = TextEditingController(text: '172.20.10.2:9091');
  final TextEditingController _passwordController = TextEditingController(text: '1234');

  dynamic ros;

  void updateConnectionStatus(bool status){
    setState(() {
      connectionStatus = status;
    });
    if(!connectionStatus) {
      ros.close();
    }
  }

  @override
  void dispose() {
    ros.close();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    if(!connectionStatus){
      return MaterialApp(
        home: Scaffold(
            backgroundColor: Colors.black,
            body: Container(
              padding: const EdgeInsets.fromLTRB(10, 50, 10, 0),
              child: Column(
                children: <Widget>[
                  const SizedBox(height: 100,),
                  const Text("Connect with DASH", style: TextStyle(color: Colors.white, fontSize: 30, fontFamily: "Poppins", fontWeight: FontWeight.bold)),
                  const SizedBox(height: 30,),
                  TextField(
                    controller: _ipController,
                    decoration: InputDecoration(
                      border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(10.0),
                      ),
                      filled: true,
                      fillColor: Colors.white,
                      hintText: 'IP Address:PORT',
                      labelStyle: TextStyle(color: Colors.grey[800]), // Text color for the label
                      hintStyle: TextStyle(color: Colors.grey[400]), // Text color for the hint
                    ),
                  ),
                  const SizedBox(height: 3,),
                  TextField(
                    controller: _passwordController,
                    decoration: InputDecoration(
                      border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(10.0),
                      ),
                      filled: true,
                      fillColor: Colors.white,
                      hintText: 'Password',
                      labelStyle: TextStyle(color: Colors.grey[800]), // Text color for the label
                      hintStyle: TextStyle(color: Colors.grey[400]), // Text color for the hint
                    ),
                  ),
                  const SizedBox(height: 20,),
                  ElevatedButton(
                      onPressed: () async {
                        String ipAdd = _ipController.text;
                        String password = _passwordController.text;

                        ros = Ros(url: 'ws://$ipAdd');
                        try{
                          ros.connect();

                          final service = Service(name: 'handshaking', ros: ros, type: "robot_interfaces/Handshake");
                          Map<String, dynamic> request = {"password":password};
                          Map<String, dynamic> response = await service.call(request);

                          if(response["correct"]){
                            updateConnectionStatus(true);
                            setState(() {
                              connectionInformation = "DASH disconnected";
                            });
                          }
                          else{
                            setState(() {
                              connectionInformation = "Make sure the details are correct\nMake sure the robot is online";
                              ros.close();
                            });
                          }
                        }
                        catch (e){
                          setState(() {
                            connectionInformation = "Make sure the details are correct\nMake sure the robot is online";
                            ros.close();
                          });
                        }
                      },
                      style: ElevatedButton.styleFrom(
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(7),
                          side: const BorderSide(color: Colors.green),
                        ),
                        backgroundColor: Colors.transparent,
                        elevation: 2,
                        minimumSize: const Size(305, 50),
                      ),
                      child: const Text("Connect", style: TextStyle(color: Colors.green, fontSize: 17, fontFamily: "Poppins",),)
                  ),
                  const SizedBox(height: 50,),
                  Text(connectionInformation, textAlign: TextAlign.center, style: const TextStyle(color: Colors.red, fontSize: 14, fontFamily: "Poppins", ),)
                ],
              ),
            )
        )
      );
    }
    else{
      return MaterialApp(
          home: Home(ros:ros, updateConnectionStatus:updateConnectionStatus)
      );
    }
  }
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
        home: Main()
    );
  }
}