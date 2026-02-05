#include <iostream>
#include <cmath>

using namespace std;

int main(){

    setlocale(LC_ALL, "rus");

    double result = sqrt(99);

    for (int i = 96; i >= 3; i -= 3){
        result = sqrt(i + result);
    }

    cout << "Сумма вложенных корней от 3 до 99 = " << result << endl;

    return 0;
}

