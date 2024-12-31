#include <iostream>
#include <iomanip>
using namespace std;

// Variables
bool a0, a1, a2, o0, o1, o2, o3, quit = false;
int choice;

// Four guidelines functions
bool areTwoOrMoreTrue() {
    int total;
    total = a0 + a1 + a2;
    if (total >= 2)
        return true;
    return false;
}

bool areTrueInputsOdd() {
    int total;
    total = a0 + a1 + a2;
    if (total % 2 == 1)
        return true;
    return false;
}

bool areFalseInputsEven() {
    int total;
    total = a0 + a1 + a2;
    if (total % 2 == 1)
        return true;
    return false;
}

bool NOTareTwoTrue() {
    int total;
    total = a0 + a1 + a2;
    if (total == 2)
        return false;
    return true;
}

// menu option 1 function
void menuOptionONE() {
    // Collect three variables
    cout << "\nPlease enter your first variable a0: ";
    cin >> a0;
    cout << "\nPlease enter your second variable a1: ";
    cin >> a1;
    cout << "\nPlease enter your third variable a2: ";
    cin >> a2;
    
    // Set the o variables based on the inputs given
    o0 = areTwoOrMoreTrue();
    o1 = areTrueInputsOdd();
    o2 = areFalseInputsEven();
    o3 = NOTareTwoTrue();
    
    // Print inputs and outputs
    cout << "\nTRUTH TABLE" << endl;
    cout << setw(3) << right << "a0";
    cout << setw(3) << right << "a1";
    cout << setw(3) << right << "a2";
    cout << setw(3) << right << "o0";
    cout << setw(3) << right << "o1";
    cout << setw(3) << right << "02";
    cout << setw(3) << right << "o3";
    cout << endl;
    cout << setw(3) << right << a0;
    cout << setw(3) << right << a1;
    cout << setw(3) << right << a2;
    cout << setw(3) << right << o0;
    cout << setw(3) << right << o1;
    cout << setw(3) << right << o2;
    cout << setw(3) << right << o3;
    cout << endl;
}

// menu option 2 function
void menuOptionTWO() {
    cout << "\nTRUTH TABLE" << endl;
    cout << setw(3) << right << "a0";
    cout << setw(3) << right << "a1";
    cout << setw(3) << right << "a2";
    cout << setw(3) << right << "o0";
    cout << setw(3) << right << "o1";
    cout << setw(3) << right << "02";
    cout << setw(3) << right << "o3";
    cout << endl;
    // Make every single combination of a0, a1, a2
    for (int i = 0; i < 2; i++) {
        a0 = i;
        for (int j = 0; j < 2; j++) {
            a1 = j;
            for (int k = 0; k < 2; k++) {
                a2 = k;
                
                // Set the o variables based on the inputs given
                o0 = areTwoOrMoreTrue();
                o1 = areTrueInputsOdd();
                o2 = areFalseInputsEven();
                o3 = NOTareTwoTrue();
    
                // Print inputs and outputs
                cout << setw(3) << right << a0;
                cout << setw(3) << right << a1;
                cout << setw(3) << right << a2;
                cout << setw(3) << right << o0;
                cout << setw(3) << right << o1;
                cout << setw(3) << right << o2;
                cout << setw(3) << right << o3;
                cout << endl;
            }
        }
    }
}


int main() {
    
    // Program description
    cout << "\nWelcome to my truth table generator!" << endl;
    cout << "This program creates truth tables using the following guidelines." << endl;
    cout << "\n1. Output o0 is true only when two or more of your input variables are true." << endl;
    cout << "2. Output o1 is true only when the number of true input variables is odd." << endl;
    cout << "3. Output o2 is true only when the number of false input variables is even." << endl;
    cout << "4. Output o3 is false only when exactly two of the input variables are true." << endl;
    
    // Menu and choice collector
    cout << "\nMenu:" << endl;
    cout << "\t1. Generate truth tables with select values" << endl;
    cout << "\t2. Generate truth tables for all values" << endl;
    cout << "\t3. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    // Continue only if cont is 'y'
    while (choice != 3) {
        
        if (choice == 1) {
            menuOptionONE();
        }
        
        if (choice == 2) {
            menuOptionTWO();
        }
        
        if (choice != 1 && choice != 2)
            cout << "Choice error! Try again...";
        
        cout << "\nMenu:" << endl;
        cout << "\t1. Generate truth tables with select values" << endl;
        cout << "\t2. Generate truth tables for all values" << endl;
        cout << "\t3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}