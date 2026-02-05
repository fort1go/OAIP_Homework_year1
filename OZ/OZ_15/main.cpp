#include <iostream>
using namespace std;

void fill_matrix(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = rand();
        }
    }
}

void print_matrix(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int matrix_norm(int** mat, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (abs(mat[i][j]) > max) {
                max = abs(mat[i][j]);
            }
        }
    }
    return max;
}

void print_min_norm_matrix(int** mat1, int size1, int** mat2, int size2, int** mat3, int size3) {
    fill_matrix(mat1, size1);
    fill_matrix(mat2, size2);
    fill_matrix(mat3, size3);
    int norm1 = matrix_norm(mat1, size1);
    int norm2 = matrix_norm(mat2, size2);
    int norm3 = matrix_norm(mat3, size3);
    if (norm2 >= norm1 && norm3 >= norm1) {
        print_matrix(mat1, size1);
    } else if (norm1 >= norm2 && norm3 >= norm2) {
        print_matrix(mat2, size2);
    } else {
        print_matrix(mat3, size3);
    }
}

int main() {
    int size = rand() % 20 + 1;
    int** matrix1 = new int*[size];
    int** matrix2 = new int*[size];
    int** matrix3 = new int*[size];
    print_min_norm_matrix(matrix1, size, matrix2, size, matrix3, size);
    return 0;
}
