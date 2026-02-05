#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    double x, eps;
    cin >> x >> eps;

    double t = 1, s = 1;
    int n = 1;
    while (abs(t) > eps) {
        t *= x / n;
        s += t;
        n++;
    }
    cout << s << endl;

    t = 1; s = 1;
    n = 1;
    while (abs(t) > eps) {
        t *= -x * x / ((2 * n - 1) * (2 * n));
        s += t;
        n++;
    }
    cout << s << endl;

    if (abs(x) >= 1) {
        cout << 0 << endl;
    }
    else {
        t = x; s = x;
        n = 2;
        while (abs(t) > eps) {
            t = -t * x * (n - 1) / n;
            s += t;
            n++;
        }
        cout << s << endl;
    }

    return 0;
}
