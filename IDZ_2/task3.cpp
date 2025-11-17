#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {

    fstream inputFile("in3.dat");
    ofstream outFile("out3.dat");
    double x, y, z, a, b;
    const double E = 2.71;
    inputFile >> x >> y >> z;

    a = (3 + pow(E, y - 1)) / (1 + x * x * fabs(y - tan(z)));
    b = 1 + fabs(y - x) + pow(y-x, 2)/2 + pow(y-x, 3)/3;

    cout << "x, y, z - " << x << ' ' << y << ' ' << z << endl;
    outFile << "a = " << a << endl;
    outFile << "b = " << b << endl;
    return 0;
}