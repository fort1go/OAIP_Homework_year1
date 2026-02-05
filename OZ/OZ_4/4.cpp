#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;
  
    while(True){
        cout << "Введите два целых значения n и m; ";
        cin >> n >> m;
        if ((m!=0 && n % m ==0) || (n!=0 && m % n == 0)){
            cout << "Найдена пара, где одно число делится на другое: " << n << " и " << m << endl;
            break;
        } 
    }
    return 0;
}
