#include <iostream>
#include <cmath>

using namespace std;

int main(){

    setlocale(LC_ALL, "rus");

    double x;
    cout << "Введите значение x: ";
    cin >> x;

    double y = sin(x);

    while (fabs(y) >= 0.0001){
        y = sin (y);
    }

    cout << "Первое полученное значение >= 0.0001: " << y << endl;

    return 0;
}

