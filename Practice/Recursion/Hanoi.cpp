#include "Hanoi.h"

void Hanoi(int n, string source, string intermediate, string destination) {
    if (n == 1) {
        cout << source << "->" << destination << "\n";
        return;
    }
    Hanoi(n - 1, source, destination, intermediate);
    Hanoi(1, source, intermediate, destination);
    Hanoi(n - 1, intermediate, source, destination);
}

void TestHanoi() {
    Hanoi(3, "A", "B", "C");
}