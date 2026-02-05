#include <iostream>
using namespace std;

void fill_matrix(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

bool is_ortonorm(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum_pair = 0;
            for (int k = 0; k < size; k++) {
                sum_pair += mat[i][k] * mat[j][k];
            }
            if (sum_pair != 0 && i != j || sum_pair != 1 && i == j) return false;

        }
    }
    return true;
}

int main() {
    int size = 10;
    int** mat = new int*[size];
    fill_matrix(mat, size);
    cout << is_ortonorm(mat, size) << endl;
    return 0;
}
