#include <iostream>
using namespace std;

//gate types
enum GATE_TYPE{DUMMY, NOT, AND, OR, NAND, NOR, HALF_ADDER, FULL_ADDER, MULTIPLEXER};

const int MAX_INPUT = 8; //maximum input is 8
int input[MAX_INPUT]; //create an integer array for inputs

int NOTgate()   { //function for NOT gate
    return input[0] == 0 ? 1 : 0; //return not gate result
}

int ANDgate(int total)  { //function for AND gate
    int i, r = input[0];

    for(i = 0; i < total; i++) //for each input
        r &= input[i]; //calculate AND operation

    return r; //return result
}

int ORgate(int total)   { //function for OR gate
    int i, r = input[0];

    for(i = 0; i < total; i++) //for each input
        r |= input[i]; //calculate OR operation

    return r; //return result
}

int NANDgate(int total) { //function for NAND gate
    input[0] = ANDgate(total); //campute AND of the inputs
    return NOTgate(); //compute and return NOT of the result
}

int NORgate(int total)  { //function for NOR gate
    input[0] = ORgate(total); //calculate OR of the inputs
    return NOTgate(); //calculate and return NOT of the result
}

void half_adder()   { //function for half adder
    int sum = 0, carry = 0; //set sum and carry as 0

    sum = input[0] + input[1]; //compute sum of two inputs
    if(sum == 2){ //both inputs are 1
        sum = 0; //set sum as 0
        carry = 1; //set carry as 1
    }
    cout << "\nSum: " << sum << endl; //print sum
    cout << "Carry: " << carry << endl; //print carry
}

void full_adder()   { //function for full adder
    int sum = 0, carry = 0; //set sum and carry as 0

    //calculate sum of inputs with carry
    sum = input[0] + input[1] + input[2];
    if(sum == 3){ //all inputs are 1s
        sum = 1; //set sum as 1
        carry = 1; //set carry as 1
    }
    else if(sum == 2){ //2 inputs are 1s
        sum = 0; //set sum as 0
        carry = 1; //set carry as 1
    }

    cout << "\nSum: " << sum << endl; //print sum
    cout << "Carry: " << carry << endl; //print carry
}

void multiplexer(int sel1, int sel2) {   //function for multiplexer
    if (sel1 == 0 && sel2 == 0) {
        cout << "\nOutput: " << input[0];
    } else if (sel1 == 0 && sel2 == 1) {
        cout << "\nOutput: " << input[1];
    } else if (sel1 == 1 && sel2 == 0) {
        cout << "\nOutput: " << input[2];
    } else if (sel1 == 1 && sel2 == 1) {
        cout << "\nOutput: " << input[3];
    } else {
        cout << "\nInvalid input selector values." << endl;
    }
}

int main(){ //main method
int ch, total, i;

while(1)    { //loop for ever
    //display menu
    cout << "MAIN MENU" << endl
    << "=========" << endl
    << "1 - NOT gate" << endl
    << "2 - AND gate" << endl
    << "3 - OR gate" << endl
    << "4 - NAND gate" << endl
    << "5 - NOR gate" << endl
    << "6 - Half-Adder" << endl
    << "7 - Full-Adder" << endl
    << "8 - Multiplexer" << endl
    << "9 - Exit" << endl
    << "Enter your choice: ";
    cin >> ch; //get choice

    switch(ch)  {
        case NOT: //NOT gate
            cout << "Enter input[0 or 1]: ";
            cin >> input[0];
            cout << "\nTable:\n";
            cout << "Input\tOutput" << endl;
            cout << "0\t1" << endl;
            cout << "1\t0" << endl;
    
            cout << "\nOutput: " << NOTgate();
            cout << endl << endl;
            break;
            
        case AND: //AND gate
            cout << "Enter total number of inputs(maximum 8): ";
            cin >> total;
            cout << "Enter inputs [0 or 1]:";
            for(i = 0; i < total; i++)
                cin >> input[i];
            cout << "\nTable:\n";
            cout << "Inputs\t\tOutput" << endl;
            cout << "0\t0\t0" << endl;
            cout << "1\t0\t0" << endl;
            cout << "0\t1\t0" << endl;
            cout << "1\t1\t1" << endl;
    
            cout << "\nOutput: " << ANDgate(total);
            cout << endl << endl;
            break;

        case OR: //OR gate
            cout << "Enter total number of inputs(maximum 8): ";
            cin >> total;
            cout << "Enter inputs [0 or 1]:";
            for(i = 0; i < total; i++)
                cin >> input[i];
            cout << "\nTable:\n";
            cout << "Inputs\t\tOutput" << endl;
            cout << "0\t0\t0" << endl;
            cout << "1\t0\t1" << endl;
            cout << "0\t1\t1" << endl;
            cout << "1\t1\t1" << endl;
    
            cout << "\nOutput: " << ORgate(total);
            cout << endl << endl;
            break;

        case NAND: //NAND gate
            cout << "Enter total number of inputs(maximum 8): ";
            cin >> total;
            cout << "Enter inputs [0 or 1]:";
            for(i = 0; i < total; i++)
                cin >> input[i];
            cout << "\nTable:\n";
            cout << "Inputs\t\tOutput" << endl;
            cout << "0\t0\t1" << endl;
            cout << "1\t0\t1" << endl;
            cout << "0\t1\t1" << endl;
            cout << "1\t1\t0" << endl;
    
            cout << "\nOutput: " << NANDgate(total);
            cout << endl << endl;
            break;
            
        case NOR: //NOR gate
            cout << "Enter total number of inputs(maximum 8): ";
            cin >> total;
            cout << "Enter inputs [0 or 1]:";
            for(i = 0; i < total; i++)
                cin >> input[i];
            cout << "\nTable:\n";
            cout << "Inputs\t\tOutput" << endl;
            cout << "0\t0\t1" << endl;
            cout << "1\t0\t0" << endl;
            cout << "0\t1\t0" << endl;
            cout << "1\t1\t0" << endl;
    
            cout << "\nOutput: " << NORgate(total);
            cout << endl << endl;
            break;

        case HALF_ADDER: //Half-adder
            cout << "Enter two inputs [0 or 1]:";
            for(i = 0; i < 2; i++)
                cin >> input[i];
            cout << "\nTable: " << endl;
            cout << "Inputs\t\tCarry\tSum" << endl;
            cout << "1\t1\t1\t0" << endl;
            cout << "1\t0\t0\t1" << endl;
            cout << "0\t1\t0\t1" << endl;
            cout << "0\t0\t0\t0" << endl;
            
            half_adder();
            cout << endl;
            break;
            
        case FULL_ADDER: //Full-adder
            cout << "Enter three inputs [0 or 1]:";
            for(i = 0; i < 3; i++)
                cin >> input[i];
            cout << "\nTable: " << endl;
            cout << "Inputs\t\t\tCarry\tSum" << endl;
            cout << "1\t1\t1\t1\t1" << endl;
            cout << "1\t1\t0\t1\t0" << endl;
            cout << "1\t0\t1\t1\t0" << endl;
            cout << "1\t0\t0\t0\t1" << endl;
            cout << "0\t1\t1\t1\t0" << endl;
            cout << "0\t1\t0\t0\t1" << endl;
            cout << "0\t0\t1\t0\t1" << endl;
            cout << "0\t0\t0\t0\t0" << endl;

            full_adder();
            cout << endl;
            break;
                
        case MULTIPLEXER: //Multiplexer
            cout << "Enter four inputs [0 or 1]:";
            for(i = 0; i < 4; i++)
                cin >> input[i];
            int sel1, sel2;
            cout << "Enter two selectors [0 or 1]:";
            cin >> sel1 >> sel2;
            cout << "\nTable: " << endl;
            cout << "Select\t\tInput\t\t\t\tOutput" << endl;
            cout << "0\t0\t0\t0\t0\t" << input[0] << "\t" << input[0] << endl;
            cout << "0\t1\t0\t0\t" << input[1] << "\t0\t" << input[1] << endl;
            cout << "1\t0\t0\t" << input[2] << "\t0\t0\t" << input[2] << endl;
            cout << "1\t1\t" << input[3] << "\t0\t0\t0\t" << input[3] << endl;
            
            multiplexer(sel1, sel2);
            cout << endl << endl;
            break;
            
        case 9: //exit
            return 0;
        }
    }
    return 0;
}