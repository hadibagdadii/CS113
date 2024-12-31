#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> setA;
vector<int> setB;
vector<int> setC;

void defineSetA();
void defineSetB();
void defineSetC();
void displayDataSet();
void defineSetAxBC();
void defineSetABxC();
void findSubset();
void findRelation();
void menu();

void defineSetA() {
  setA.clear();
  cout << "\nEnter the number of elements in set A: ";
  int n;
  cin >> n;
  cout << "Enter the elements of set A: ";
  int element;
  for (int i = 0; i < n; i++) {
    cin >> element;
    setA.push_back(element);
  }
}

void defineSetB() {
  setB.clear();
  cout << "Enter the number of elements in set B: ";
  int n;
  cin >> n;
  cout << "Enter the elements of set B: ";
  int element;
  for (int i = 0; i < n; i++) {
    cin >> element;
    setB.push_back(element);
  }
}

void defineSetC() {
  setC.clear();
  cout << "Enter the number of elements in set C: ";
  int n;
  cin >> n;
  cout << "Enter the elements of set C: ";
  int element;
  for (int i = 0; i < n; i++) {
    cin >> element;
    setC.push_back(element);
  }
}

void displayDataSet() {
    cout << "Set A: ";
    for (int i : setA) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Set B: ";
    for (int i : setB) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Set C: ";
    for (int i : setC) {
        cout << i << " ";
    }
    cout << endl;
}

vector<pair<int, int> > cartesianProduct(vector<int> &a, vector<int> &b) {
    vector<pair<int, int> > result;
    for (int i : a) {
        for (int j : b) {
            result.push_back({i, j});
            cout << i << ", " << j << endl;
        }
    }
    return result;
}

void findSubset() {
    int x;
    cout << "Enter value to find: ";
    cin >> x;
    if (find(setA.begin(), setA.end(), x) != setA.end()) {
        cout << x << " is in set A" << endl;
    } else if (find(setB.begin(), setB.end(), x) != setB.end()) {
        cout << x << " is in set B" << endl;
    } else if (find(setC.begin(), setC.end(), x) != setC.end()) {
        cout << x << " is in set C" << endl;
    } else {
        cout << x << " is not in any set" << endl;
    }
}

// void findRelationR(){
//     int x, y;
//     cout << "Enter two values to find the relation: ";
//     cin >> x >> y;
//     if (find(setA.begin(), setA.end(), x) != setA.end() && find(setB.begin(), setB.end(), y))
// }

void menu() {
    cout << "Please select an option" << endl;
    cout << "1) Define Set A" << endl;
    cout << "2) Define Set B" << endl;
    cout << "3) Define Set C" << endl;
    cout << "4) Display the Data Set" << endl;
    cout << "5) Cartesian Product A x B" << endl;
    cout << "6) Cartesian Product B x C" << endl;
    cout << "7) Cartesian Product (A x B) x C" << endl;
    cout << "8) Cartesian Product A x (B x C)" << endl;
    cout << "9) Find the Subset" << endl;
    cout << "10) Find the Relation R" << endl;
    cout << "x) Exit" << endl;
    cout << "\nYour option:";
}

int main() {
    string choice;
    do
    {
        menu();
        cin >> choice;
        cout << endl;

        if (choice == "x")
        {
            cout << "\nGoodbye!" << endl;
            return 0;
        }
        
        int num = stoi(choice);
        vector<pair<int, int> > result;

        switch(num)
        {
        case 1:
            defineSetA();
            break;
        
        case 2:
            defineSetB();
            break;
        
        case 3:
            defineSetC();
            break;
        
        case 4:
            displayDataSet();
            break;
        
        case 5:
            cout << "Cartesian Product AxB" << endl;
            result = cartesianProduct(setA, setB);
            break;
        
        case 6:
            cout << "Cartesian Product BxC" << endl;
            result = cartesianProduct(setB, setC);
            break;
        
        case 7:
            cout << "Cartesian Product (AxB)xC" << endl;
            break;
        
        case 8:
            cout << "Cartesian Product Ax(BxC)" << endl;
            break;
        
        case 9:
            cout << "Subset" << endl;
            findSubset();
            break;
        
        default:
            break;
        }
    } while (choice != "x");
}