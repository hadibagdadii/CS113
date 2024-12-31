#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printAncestorTable(int generations) {
    int totalAncestors = 0;

    cout << setw(20) << left << "Position in the row:";
    for (int i = 1; i <= generations; i++) {
        int ancestors = pow(2, i - 1);
        totalAncestors += ancestors;
        cout << setw(4) << right << i;
    }
    cout << "\n";

    cout << setw(20) << left << "Number of ancestors:";
    for (int i = 1; i <= generations; i++) {
        int ancestors = pow(2, i);
        cout << setw(4) << right << ancestors;
    }
}

int main() {
    int generations;
    cout << "Enter the number of generations: ";
    cin >> generations;

    printAncestorTable(generations);

    return 0;
}
