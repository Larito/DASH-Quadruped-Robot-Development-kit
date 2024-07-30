import 'package:flutter/material.dart';
import 'package:roslibdart/roslibdart.dart';

class Settings extends StatefulWidget {
  dynamic ros, updateConnectionStatus;

  Settings({super.key, required this.ros, required this.updateConnectionStatus});

  @override
  State<Settings> createState() => _SettingsState();
}

class _SettingsState extends State<Settings> {
  TextEditingController _fullNameController = TextEditingController();
  TextEditingController _ageController = TextEditingController();
  TextEditingController _bloodTypeController = TextEditingController();
  TextEditingController _medicalNotesController = TextEditingController();
  TextEditingController _allergiesController = TextEditingController();
  TextEditingController _weightController = TextEditingController();
  TextEditingController _heightController = TextEditingController();
  TextEditingController _primaryLanguageController = TextEditingController();
  TextEditingController _passwordController = TextEditingController();

  @override
  void initState() {
    super.initState();
    _getSettings();
  }

  Future<void> _getSettings() async {
    final service = Service(name: 'settings_handler', ros: widget.ros, type: "robot_interfaces/Config");
    Map<String, dynamic> request = {
      "full_name":"",
      "age":"",
      "blood_type":"",
      "medical_notes":"",
      "allergies": "",
      "weight":"",
      "height":"",
      "primary_language":"",
      "password":"",
      "requesting":true
    };

    try {
      final response = await service.call(request);
      _fullNameController.text = response["full_name"];
      _ageController.text = response["age"];
      _bloodTypeController.text = response["blood_type"];
      _medicalNotesController.text = response["medical_notes"];
      _allergiesController.text = response["allergies"];
      _weightController.text = response["weight"];
      _heightController.text = response["height"];
      _primaryLanguageController.text = response["primary_language"];
      _passwordController.text = response["password"];
    } finally {
      setState(() {});
    }
  }

  Future<void> _saveSettings() async {
    final service = Service(name: 'settings_handler', ros: widget.ros, type: "robot_interfaces/Config");
    Map<String, dynamic> request = {
      "full_name": _fullNameController.text,
      "age": _ageController.text,
      "blood_type": _bloodTypeController.text,
      "medical_notes": _medicalNotesController.text,
      "allergies": _allergiesController.text,
      "weight": _weightController.text,
      "height": _heightController.text,
      "primary_language": _primaryLanguageController.text,
      "password": _passwordController.text,
      "requesting": false
    };

    try {
      await service.call(request);
    } finally {
      setState(() {});
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text(
          'Settings',
          style: TextStyle(
            fontFamily: 'Poppins',
            fontWeight: FontWeight.bold,
            color: Colors.white,
            fontSize: 24,
          ),
        ),
        backgroundColor: Colors.black,
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text(
              'User Details',
              style: TextStyle(
                fontFamily: 'Poppins',
                fontWeight: FontWeight.bold,
                color: Colors.white,
                fontSize: 22,
              ),
            ),
            const SizedBox(height: 16),
            _buildTextField('Name', 'Full Name', TextInputType.text, _fullNameController),
            _buildTextField('Age', 'Age', TextInputType.number, _ageController),
            _buildTextField('Blood Type', 'Blood Type', TextInputType.text, _bloodTypeController),
            _buildTextField('Medical Notes', 'Medical Notes', TextInputType.text, _medicalNotesController),
            _buildTextField('Allergies', 'Allergies', TextInputType.text, _allergiesController),
            _buildTextField('Weight', 'Weight', TextInputType.number, _weightController),
            _buildTextField('Height', 'Height', TextInputType.text, _heightController),
            _buildTextField('Primary Language', 'Primary Language', TextInputType.text, _primaryLanguageController),
            const SizedBox(height: 16),
            const Text(
              'Account Information',
              style: TextStyle(
                fontFamily: 'Poppins',
                fontWeight: FontWeight.bold,
                color: Colors.white,
                fontSize: 22,
              ),
            ),
            const SizedBox(height: 16),
            _buildTextField('Password', 'Password', TextInputType.text, _passwordController, obscureText: true),
            const SizedBox(height: 16),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ElevatedButton(
                  onPressed: () {
                    _saveSettings();
                  },
                  style: ElevatedButton.styleFrom(
                      backgroundColor: Colors.green
                  ),
                  child: const Text(
                    'Save',
                    style: TextStyle(
                      fontFamily: 'Poppins',
                      fontWeight: FontWeight.bold,
                      color: Colors.white,
                      fontSize: 16,
                    ),
                  ),
                ),
                ElevatedButton(
                  onPressed: () {
                    Navigator.pop(context);
                  },
                  style: ElevatedButton.styleFrom(
                      backgroundColor: Colors.red
                  ),
                  child: const Text(
                    'Back',
                    style: TextStyle(
                      fontFamily: 'Poppins',
                      fontWeight: FontWeight.bold,
                      color: Colors.white,
                      fontSize: 16,
                    ),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 30,)
          ],
        ),
      ),
    );
  }

  Widget _buildTextField(String label, String placeholder, TextInputType inputType, TextEditingController controller, {bool obscureText = false}) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(
            label,
            style: const TextStyle(
              fontFamily: 'Poppins',
              fontWeight: FontWeight.bold,
              color: Colors.white,
              fontSize: 16,
            ),
          ),
          const SizedBox(height: 8),
          TextField(
            controller: controller,
            keyboardType: inputType,
            obscureText: obscureText,
            decoration: InputDecoration(
              hintText: placeholder,
              hintStyle: const TextStyle(
                fontFamily: 'Poppins',
                color: Colors.grey,
              ),
              filled: true,
              fillColor: Colors.white,
              border: const OutlineInputBorder(),
            ),
            style: const TextStyle(
              fontFamily: 'Poppins',
              color: Colors.black,
            ),
          ),
        ],
      ),
    );
  }
}
