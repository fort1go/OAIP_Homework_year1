#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double N, D, eps;
    cin >> N >> D >> eps;

    double xn, x = 0.1; // Чем меньше x, тем точнее
    for (int n = 1;n <= 100;n++){
        xn = x * (2 - D * x);
        if (fabs(xn - x) <= eps){break;}
        x = xn;
    }
    cout << N * xn << endl;
    return 0;
}
