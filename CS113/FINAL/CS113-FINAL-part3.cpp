#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

void testSubset(const unordered_set<int>& setA, const unordered_set<int>& setB) {

  // Check if Set A is a subset of Set B
  bool isSubset = true;
  for (int element : setA) {
    if (setB.count(element) == 0) {
        isSubset = false;
        break;
    }
  }

  if (isSubset) {
    cout << "\nSet A is a subset of Set B.\n";
    cout << "Elements in Set A:\n";
    for (int element : setA) {
      cout << element << " ";
    }
    cout << "\n";
  } 
  
  else {
    cout << "\nSet A is not a subset of Set B.\n";
    cout << "Elements not in Set B:\n";
    for (int element : setA) {
      if (setB.count(element) == 0) {
        cout << element << " ";
      }
    }
    cout << "\n";
  }
}

int main() {
  char choice;
  do {
    cout << "Enter the number of elements in Set A (minimum 5): ";
    int sizeA;
    cin >> sizeA;

    if (sizeA < 5) {
      cout << "Invalid size. Minimum size for Set A is 5.\n";
      continue;
    }

    unordered_set<int> setA;

    cout << "Enter the elements of Set A: ";
    for (int i = 0; i < sizeA; ++i) {
      int element;
      cin >> element;
      setA.insert(element);
    }

    cout << "\nEnter the number of elements in Set B (minimum 5): ";
    int sizeB;
    cin >> sizeB;

    if (sizeB < 5) {
      cout << "Invalid size. Minimum size for Set B is 5.\n";
      continue;
    }

    unordered_set<int> setB;

    cout << "Enter the elements of Set B: ";
    for (int i = 0; i < sizeB; ++i) {
      int element;
      cin >> element;
      setB.insert(element);
    }

    testSubset(setA, setB);

    cout << "\nDo you want to test another pair of sets? (y/n): ";
    cin >> choice;
    cout << "\n";
  } while (choice == 'y' || choice == 'Y');
  
  cout << "\nGoodbye!";
  return 0;
}
