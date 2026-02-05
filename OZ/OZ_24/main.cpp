#include <iostream>
using namespace std;

void christmas_tree(const int height, const int row) {
    for (int i = 1; i <= height - row; i++) {
        cout << " ";
    }
    for (int i = 1; i <= 1 + (row - 1) * 2; i++) {
        cout << "#";
    }
    cout << endl;
    if (height == row) {
        for (int i = 1; i <= height - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    } else {
        christmas_tree(height, row + 1);
    }
}

int main() {
    int height;
    cin >> height;
    christmas_tree(height, 1);
}
