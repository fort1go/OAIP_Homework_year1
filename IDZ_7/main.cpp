#include <iostream>
#include <cmath>

using namespace std;

double y(double x, int N) {
    if (N == 1) {
        return sqrt(x * x);
    } else {
        return sqrt(x * x + y(x, N - 1));
    }
}

int main() {
    double x;
    int N;
    cin >> x >> N;
    double result = y(x, N) - 2;
    cout << result << endl;
    return 0;
}
