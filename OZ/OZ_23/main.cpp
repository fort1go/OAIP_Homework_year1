#include <iostream>
using namespace std;

int fib_recursive(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

int fib_loop(int n) {
    int a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    cout << fib_recursive(10) << endl;
    cout << fib_loop(10) << endl;
    return 0;
}
