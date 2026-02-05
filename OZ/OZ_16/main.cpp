#include <iostream>
#include <cmath>
using namespace std;

double trapezoidal_integral(double (*f)(double), double a, double b, int n) {
    if (n <= 0) return 0.0;

    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * ( (f(a) + f(b)) / 2.0 + sum );
}

double f1(double x) {
    return x * x;
}

double f2(double x) {
    return sin(x);
}

int main() {
    double c, d;
    cout << "Enter c and d (c < d): ";
    cin >> c >> d;

    double integral1 = trapezoidal_integral(f1, c, d, 20);

    double integral2 = trapezoidal_integral(f2, 0.0, M_PI, 100);

    double total = integral1 + integral2;

    cout << "Result: " << total << endl;
    return 0;
}
