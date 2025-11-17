#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    double a, a2, a4, a5, a8, a13;
    cout << "Введите a: ";
    cin >> a;

    a2 = a * a;
    a4 = a2 * a2;
    a5 = a4 * a;
    a8 = a4 * a4;
    a13 = a8 * a5;

    cout << "Входные данные - " << a << endl;
    cout << "a5 - " << a5 << endl;
    cout << "a13 - " << a13 << endl;

    return 0;
}
