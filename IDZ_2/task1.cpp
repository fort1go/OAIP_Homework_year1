#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cout << "Введите x и y: ";
    cin >> x >> y;
    cout << (fabs(x) - fabs(y)) / (1 + fabs(x * y)) << endl;
    return 0;
}
