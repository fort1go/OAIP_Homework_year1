#include <iostream>
using namespace std;

int main() {
    double N, D, eps;
    cin >> N >> D >> eps;

    double x = 0.5;
    for (int i = 0; i < 100; i++) {
        double nx = x * (2 - D * x);
        if (nx - x < eps && x - nx < eps) {
            x = nx;
            break;
        }
        x = nx;
    }

    cout << N * x << endl;
    return 0;
}
