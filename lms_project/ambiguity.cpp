#include <iostream>
using namespace std;

int add(int a, int b) {
    cout << "Called int version\n";
    return a + b;
}

float add(float a, float b) {
    cout << "Called float version\n";
    return a + b;
}

int main() {
    cout << "Sum: " << add(5.0, 6.6) << endl; // ⚠️ Ambiguity

    return 0;
}
