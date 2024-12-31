#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
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
void menu();
void isRelationR(const vector<int> &set1, const vector<int> &set2);

void defineSetA() {
  setA.clear();
  cout << "Enter the number of elements in set A: ";
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
    cout << "The length of the Cartesian product is: " << result.size() << endl;
    return result;
}

void cartesianProductAxBC() {
    std::vector<std::tuple<int, int, int>> result;
    for (int a : setA) {
        for (int b : setB) {
            for (int c : setC) {
                result.emplace_back(a, b, c);
                cout << a << ", " << b << ", " << c << endl;
            }
        }
    }
    cout << "The length of the Cartesian product is: " << result.size() << endl;
    return ;
}

void cartesianProductABxC() {
    std::vector<std::tuple<int, int, int>> result;
    for (int a : setA) {
        for (int b : setB) {
            for (int c : setC) {
                result.emplace_back(make_tuple(a, b, c));
                cout << a << ", " << b << ", " << c << endl;
            }
        }
    }
    cout << "The length of the Cartesian product is: " << result.size() << endl;
    return ;
}

void findSubset() {
    cout << "Enter number of first set:";
    int x, y;
    cin >> x;
    cout << "Enter number of second set:";
    cin >> y;
    cout << endl;
    
    sort(setA.begin(), setA.end());
    sort(setB.begin(), setB.end());
    sort(setC.begin(), setC.end());
    
    if (x==1 && y==1) {
        if (includes(setA.begin(), setA.end(), setA.begin(), setA.end())) {
            cout << "setA is a subset of setA";
        }
        else
            cout << "setA is not a subset of setA";
    }
    
    if (x==1 && y==2) {
        if (includes(setA.begin(), setA.end(), setB.begin(), setB.end())) {
            cout << "setA is a subset of setB";
        }
        else
            cout << "setA is not a subset of setB";
    }
    
    if (x==1 && y==3) {
        if (includes(setA.begin(), setA.end(), setC.begin(), setC.end())) {
            cout << "setA is a subset of setC";
        }
        else
            cout << "setA is not a subset of setC";
    }
    
    if (x==2 && y==1) {
        if (includes(setB.begin(), setB.end(), setA.begin(), setA.end())) {
            cout << "setB is a subset of setA";
        }
        else
            cout << "setB is not a subset of setA";
    }
    
    if (x==2 && y==2) {
        if (includes(setB.begin(), setB.end(), setB.begin(), setB.end())) {
            cout << "setB is a subset of setB";
        }
        else
            cout << "setB is not a subset of setB";
    }
    
    if (x==2 && y==3) {
        if (includes(setB.begin(), setB.end(), setC.begin(), setC.end())) {
            cout << "setB is a subset of setC";
        }
        else
            cout << "setB is not a subset of setC";
    }
    
    
    if (x==3 && y==1) {
        if (includes(setC.begin(), setC.end(), setA.begin(), setA.end())) {
            cout << "setC is a subset of setA";
        }
        else
            cout << "setC is not a subset of setA";
    }
    
    if (x==3 && y==2) {
        if (includes(setC.begin(), setC.end(), setB.begin(), setB.end())) {
            cout << "setC is a subset of setB";
        }
        else
            cout << "setC is not a subset of setB";
    }
    
    if (x==3 && y==3) {
        if (includes(setC.begin(), setC.end(), setC.begin(), setC.end())) {
            cout << "setC is a subset of setC";
        }
        else
            cout << "setC is not a subset of setC";
    }
    cout << endl;
    return;
}

void isRelationR(const vector<int> &set1, const vector<int> &set2) {
    if (set1.size() != set2.size()) {
        cout << "\nNot in relation R" << endl;
        return;
    }

    for (int i = 0; i < set1.size(); i++) {
        if ((set1[i] - set2[i]) % 2 != 0) {
            cout << "\nNot in relation R" << endl;
            return;
        }
    }

    cout << "\nIn relation R" << endl;
    return;
}

void menu() {
    cout << "\nPlease select an option" << endl;
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
            cartesianProductABxC();
            break;
        
        case 8:
            cout << "Cartesian Product Ax(BxC)" << endl;
            cartesianProductAxBC();
            break;
        
        case 9:
            findSubset();
            break;
            
        case 10:
            cout << "Enter number of first set:";
            int x, y;
            cin >> x;
            cout << "Enter number of second set:";
            cin >> y;
            
            if (x==1 && y==1) {
                isRelationR(setA, setA);
            }
            
            if (x==1 && y==2) {
                isRelationR(setA, setB);
            }
            
            if (x==1 && y==3) {
                isRelationR(setA, setC);
            }
            
            if (x==2 && y==1) {
                isRelationR(setB, setA);
            }
            
            if (x==2 && y==2) {
                isRelationR(setB, setB);
            }
            
            if (x==2 && y==3) {
                isRelationR(setB, setC);
            }
            
            if (x==3 && y==1) {
                isRelationR(setC, setA);
            }
            
            if (x==3 && y==2) {
                isRelationR(setC, setB);
            }
            
            if (x==3 && y==3) {
                isRelationR(setC, setC);
            }
            break;
        
        default:
            break;
        }
    } while (choice != "x");
    return 0;
}
