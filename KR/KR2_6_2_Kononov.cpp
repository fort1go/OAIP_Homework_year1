#include <iostream>
#include <string>
using namespace std;

double A[11];

double max(double* array, int n) {
    if (n == 0) {
        return array[0];
    } else {
        double pre_max = max(array, n - 1);
        if (pre_max > array[n]) {
            return pre_max;
        } else {
            return array[n];
        }
    }
}


int main() {
    A[0] = 1.5;
    A[1] = 42.0;
    A[2] = 99.9;
    A[3] = 123.45;
    A[4] = 256.78;
    A[5] = 500.0;
    A[6] = 789.12;
    A[7] = 3.14;
    A[8] = 16.0;
    A[9] = 88.88;
    A[10] = 404.0;

    cout << max(A, 19) << endl;
    
    return 0;
}


