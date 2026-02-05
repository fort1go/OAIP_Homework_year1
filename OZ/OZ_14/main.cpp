#include <iostream>
using namespace std;

void fill_vector(double* vec, int size) {
    for (int i = 0; i < size; i++) {
        vec[i] = rand();
    }
}

void fill_matrix(double** mat, int size) {
    for (int i = 0; i < size; i++) {
        mat[i] = new double[size];
        fill_vector(mat[i], size);
    }
}

void print_vector(double* vec, int size) {
    for (int i = 0; i < size; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void print_matrix(double** mat, int size) {
    for (int i = 0; i < size; i++) {
        print_vector(mat[i], size);
    }
}

void multiply_matrix_by_vector(double** mat, double* vec, double* res, int size) {
    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            sum += mat[i][j] * vec[j];
        }
        res[i] = sum;
    }
}

double multiply_vector_by_vector(double* vec1, double* vec2, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += vec1[i] * vec2[i];
    }
    return sum;
}


int main() {
    int size = rand() % 9 + 1;
    double* vecX = new double[size];
    double* vecY = new double[size];
    double** matA = new double*[size];
    double** matB = new double*[size];
    double** matC = new double*[size];

    double* vecAx = new double[size];
    double* vecBy = new double[size];
    double* vecCx = new double[size];

    fill_vector(vecX, size);
    fill_vector(vecY, size);
    fill_matrix(matA, size);
    fill_matrix(matB, size);
    fill_matrix(matC, size);

    cout << "Vector x:" << endl;
    print_vector(vecX, size);
    cout << "Vector y:" << endl;
    print_vector(vecY, size);
    cout << "Matrix A:" << endl;
    print_matrix(matA, size);
    cout << "Matrix B:" << endl;
    print_matrix(matB, size);
    cout << "Matrix C:" << endl;
    print_matrix(matC, size);

    multiply_matrix_by_vector(matA, vecX, vecAx, size);
    multiply_matrix_by_vector(matB, vecY, vecBy, size);
    multiply_matrix_by_vector(matC, vecX, vecCx, size);

    cout << "Vector Ax:" << endl;
    print_vector(vecAx, size);
    cout << "Vector By:" << endl;
    print_vector(vecBy, size);
    cout << "Vector Cx:" << endl;
    print_vector(vecCx, size);

    double Ax_By = multiply_vector_by_vector(vecAx, vecBy, size);
    double Cx_y = multiply_vector_by_vector(vecCx, vecY, size);
    double x_By = multiply_vector_by_vector(vecX, vecBy, size);

    cout << "(Ax, By): " << Ax_By << endl;
    cout << "(Cx, y): " << Cx_y << endl;
    cout << "(x, By): " << Ax_By << endl;

    if (x_By < 1e-9) {
        cout << "Zero division" << endl;
        return 0;
    }
    double result = Ax_By + Cx_y / x_By;
    cout << "Result: " << result << endl;

    return 0;
}
