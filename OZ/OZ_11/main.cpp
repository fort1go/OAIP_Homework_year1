#include <iostream>
using namespace std;

bool is_magic_square(unsigned int** mat, unsigned int size) {
    bool used_numbers[size*size];
    for (int i = 0; i < size*size; i++) {
        used_numbers[i] = false;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mat[i][j] < 1 || mat[i][j] > size*size) return false;
            if (used_numbers[mat[i][j] - 1]) return false;
            used_numbers[mat[i][j] - 1] = true;
        }
    }
    int target_sum = 0;
    int diagonal_sum = 0;
    int diagonal_sum_reverse = 0;
    for (int i = 0; i < size; i++) {
        target_sum += mat[0][i];
    }
    for (int i = 0; i < size; i++) {
        diagonal_sum += mat[i][i];
        diagonal_sum_reverse += mat[i][size-i-1];
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < size; j++) {
            row_sum += mat[i][j];
            col_sum += mat[j][i];
        }
        if (row_sum != target_sum || col_sum != target_sum) return false;
    }
    if (diagonal_sum != target_sum || diagonal_sum_reverse != target_sum) return false;
    return true;
}

int main() {
    int size = 3;
    unsigned int** mat = new unsigned int*[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new unsigned int[size];
    }
    mat[0][0] = 8;
    mat[0][1] = 1;
    mat[0][2] = 6;
    mat[1][0] = 3;
    mat[1][1] = 5;
    mat[1][2] = 7;
    mat[2][0] = 4;
    mat[2][1] = 9;
    mat[2][2] = 2;
    cout << is_magic_square(mat, size);
    return 0;
}
