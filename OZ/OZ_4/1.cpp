#include <iostream>

using namespace std;

int factorial_for(){
    int result = 1;
    for (int i = 1; i<=10; i++){
        result*=i;
    }
    return result;
}

int factorial_while(){
    int result = 1;
    int i = 1;
    while (i <= 10){
        result*=i;
        i++;
    }
    return result;
}

int factorial_do_while(){
    int result = 1;
    int i = 1;
    do{
        result*=i;
        i++;
    } while (i <= 10);
    return result;
}

int main(){

    setlocale(LC_ALL, "rus");

    cout << "Факториал 10! через цикл for: " << factorial_for() << endl;
    cout << "Факториал 10! через цикл while: " << factorial_while() << endl;
    cout << "Факториал 10! через цикл do-while: " << factorial_do_while() << endl;

    return 0;
}
