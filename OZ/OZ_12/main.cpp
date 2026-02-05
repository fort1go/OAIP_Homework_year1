#include <iostream>
using namespace std;

void fill_matrix_10x15(int** mat) {
    for (int i = 0; i < 10; i++) {
        mat[i] = new int[15];
        for (int j = 0; j < 15; j++) {
            mat[i][j] = rand();
        }
    }
}

void print_dots_10x15_mat(int** mat) {
    int min_row[10];
    int min_col[15];
    int max_row[10];
    int max_col[15];
    for (int i = 0; i < 10; i++) {
        min_row[i] = INT_MAX;
        max_row[i] = INT_MIN;
    }
    for (int i = 0; i < 15; i++) {
        min_col[i] = INT_MAX;
        max_col[i] = INT_MIN;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            if (min_row[i] > mat[i][j]) {
                min_row[i] = mat[i][j];
            }
            if (min_col[j] > mat[i][j]) {
                min_col[j] = mat[i][j];
            }
            if (max_row[i] < mat[i][j]) {
                max_row[i] = mat[i][j];
            }
            if (max_col[j] < mat[i][j]) {
                max_col[j] = mat[i][j];
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            if (min_row[i] == mat[i][j] && max_col[j] == mat[i][j] || max_row[i] == mat[i][j] && min_col[j] == mat[i][j]) {
                cout << i << " " << j << endl;
            }
        }
    }
}

int main() {
    int** mat = new int*[10];
    fill_matrix_10x15(mat);
    print_dots_10x15_mat(mat);
    return 0;
}
