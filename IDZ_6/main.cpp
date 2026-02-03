#include <iostream>
#include <cmath>

using namespace std;

double mediana(double a, double b, double c) {
    return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    double AN = mediana(a, b, c);
    double BL = mediana(b, a, c);
    double CM = mediana(c, a, b);
    
    double A1N1 = mediana(AN, BL, CM);
    double B1L1 = mediana(BL, AN, CM);
    double C1M1 = mediana(CM, AN, BL);
    
    cout << A1N1 << " " << B1L1 << " " << C1M1 << endl;
    
    return 0;
}
