#include <iostream>
#include <iomanip>

using namespace std;

bool result(bool x, bool y, bool z) {
  bool temp1 = (x || (!y && z));
  bool temp2 = (x && (y && 1));
  return temp1 || temp2;
}

int main() {
  cout << "Truth Table for p(x, y, z) = (x V (~y ∧ z)) V (x ∧ (y ∧ 1)):\n";
  cout << "x" << setw(3) << "y" << setw(3) << "z" << setw(3) << "  Output\n";

  for (bool x : {0, 1}) {
    for (bool y : {0, 1}) {
      for (bool z : {0, 1}) {
        bool output = result(x, y, z);
        cout << x << setw(3) << y << setw(3) << z << setw(5) << output << '\n';
      }
    }
  }

  return 0;
}