#include <iostream>
using namespace std;

double** gen_matrix(int i, int j) {
    double** matrix = new double*[i];
    for (int k = 0; k < i; k++) {
        matrix[k] = new double[j];
        for (int l = 0; l < j; l++) {
            matrix[k][l] = rand() % 100;
        }
    }
    return matrix;
}

void fill_vecC(double** matrix, int rows, int j, int k, int p, double* vector, int n) {
    // j > p && i >= n >= k
    for (int i = 0; i < k; i++) {
        double sum = 0;
        for (int j = 0; j < p; j++) {
            sum += matrix[i][j];
        }
        vector[i] = sum;
    }
}

int main() {
    // Проверка
    int i = 8, j = 6, k = 4, p = 4;
    int n = 5;
    double** A = gen_matrix(i, j);

    double C[n];
    for (int i = 0; i < n; i++) {
        C[i] = rand() % 100;
    }

    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            cout << A[k][l] << " ";
        }
        cout << endl;
    }

    fill_vecC(A, i, j, k, p, C, n);
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << C[i] << " ";
    }

    cout << endl;
    return 0;
}
