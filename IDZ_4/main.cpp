#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {

    int k = 1;
    float y_k = 2.0/3.0, y_k_1, eps = 0.000001, val;
    

    for(k;1;k++){
        y_k_1 = (y_k + 1)/(y_k + 2);
        if (fabs(y_k_1-y_k) < eps){
            cout << y_k_1 << endl;
            return 0;
        }
        y_k = y_k_1;
    }
    
    return 0;
}