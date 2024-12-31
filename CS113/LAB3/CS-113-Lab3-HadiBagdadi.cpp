#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <fstream>
#include <vector>

using namespace std;

// Device struct to store device information
struct Device {
    int ID;
    string name, desc;
    bool state;
};


// Function to convert binary string to decimal and hex
// void convertBinary(string binary) {
//     bitset<8> bits(binary);
//     int decimal = bits.to_ulong();
//     string hex = "0123456789ABCDEF";
//     string result = "";
//     while (decimal > 0) {
//         result = hex[decimal % 16] + result;
//         decimal /= 16;
//     }
//     cout << "Binary: " << binary << ", Decimal: " << bits.to_ulong() << ", Hex: " << result << endl;
// }

string add_logical(string& rule) {
    string statement;
    cout << "***** Define the Logical Argument *****" << endl;
    cout << "Enter statement: ";
    cin.ignore(); // Clear any leftover input from the input stream
    getline(cin, statement);
    rule = rule + statement;
    return rule;
}


string add_conditional(string& rule) {
    int choice;
    cout << "***** Define the Conditional Operator *****" << endl;
    cout << "1) AND" << endl;
    cout << "2) OR" << endl;
    cout << "3) NOT" << endl;
    cout << "4) THEN" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;
    
    switch (choice) {
        case 1:
            rule = rule + " AND ";
            break;
        
        case 2:
            rule = rule + " OR ";
            break;
        
        case 3:
            rule = rule + " NOT ";
            break;
        
        case 4:
            rule = rule + " THEN ";
            break;
    }
    return rule;
}

int main() {
    // List of smart devices
    fstream rules, devices;
    rules.open("rules.txt", ios::in | ios::out | ios::app);
    devices.open("devices.txt", ios::in | ios::out | ios::app);
    
    vector<Device> device_list;
    Device temp;
    
    while(devices >> temp.ID) {
        getline(devices, temp.name, '#');
        getline(devices, temp.desc, '#');
        devices >> temp.state;
        device_list.push_back(temp);
    }
    
    char cont = 'y', turn;
    string rule = "", lines;
    int index, cond, deviceID;

    // Menu loop
    while (cont == 'y') {
        
        index = 1;
        
        // Display menu options
        cout << "\nSelect an option:" << endl;
        cout << "1) Define Logical Argument" << endl;
        cout << "2) Turn smart-device O/I state" << endl;
        cout << "3) Show summary of the rules" << endl;
        cout << "4) Show table summary of the devices on state" << endl;
        cout << "5) Show table summary of the devices off state" << endl;
        cout << "6) Exit" << endl;
        cout << "\nOption: ";
        int option;
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: 
                // Get rule input from user
                rule = add_logical(rule);
                char addlog;
                do {
                    cout << "Do you wish to add a logical statement? (y/n) : ";
                    cin >> addlog;
                    if (addlog == 'y') {
                        rule = add_conditional(rule);
                        rule = add_logical(rule);
                    }
                } while (addlog != 'n');
                
                rules << rule << endl;
                cout << "Rule: " << rule << endl;
                break;
            
            case 2:
                cout << "Devices:" << endl;
                for (const Device& device : device_list) {
                    cout << index++ << ")";
                    cout << "  ID: " << device.ID;
                    cout << "\tName: " << setw(30) << left << device.name;
                    cout << "State: " << (device.state ? "ON" : "OFF") << endl;
                }
                
                do {
                    cout << "Enter the ID of the device you want to toggle: ";
                    cin >> deviceID;
    
                    // Search for the device with the given ID in the vector
                    for (auto& device : device_list) {
                        if (device.ID == deviceID) {
                        // Toggle the device's state
                        device.state = !device.state;
            
                         // Print a message indicating the new state of the device
                        cout << "\n" << device.name << " is now " << (device.state ? "ON" : "OFF") << endl;
                        }
                    }
                    cout << "\nDo you wish to toggle another device? (y/n) : ";
                    cin >> turn;
                } while (turn == 'y');
                
                devices.close();
                devices.open("devices.txt", ios::in | ios::out | ios::trunc);
                for (const Device& device : device_list) {
                    devices << device.ID;
                    devices << " " << device.name << '#';
                    devices << device.desc << '#';
                    devices << device.state << endl;
                }
                devices.close();
                devices.open("devices.txt", ios::in | ios::out | ios::app);
                break;
                
            case 3:
                cout << endl;
                while (getline(rules, lines, '.'))
                    cout << lines << '.' << endl;
                break;
                
            case 4:
                cout << "ON Devices:" << endl;
                for (const Device& device : device_list) {
                    if (device.state == 1) {
                        cout << index++ << ")";
                        cout << "\tID: " << device.ID;
                        cout << "\tName: " << device.name;
                        cout << endl;
                    }
                }
                break;
            
            case 5:
                cout << "OFF Devices:" << endl;
                for (const Device& device : device_list) {
                    if (device.state == 0) {
                        cout << index++ << ")";
                        cout << "\tID: " << device.ID;
                        cout << "\tName: " << device.name;
                        cout << endl;
                    }
                }
                break;
                
            case 6:
                cont = 'n';
                break;
        }
    }
    rules.close();
    devices.close();
    return 0;
}
            