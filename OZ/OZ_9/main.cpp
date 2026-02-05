#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M, K;
    
    cout << "Ввод размеров N, M, K: ";
    cin >> N >> M >> K;
    int Amatrix[N][M];
    int Bmatrix[M][K];
    int Cmatrix[N][K];

    //Ввод матрицы вручную
    cout << "Ввод первой матрицы: ";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Amatrix[i][j];
        }
    }

    cout << "Ввод второй матрицы: ";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Bmatrix[i][j];
        }
    }

    //Рандомная матрица
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         Amatrix[i][j] = rand() % 10;
    //     }
    // }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < K; j++) {
    //         Bmatrix[i][j] = rand() % 10;
    //     }
    // }

    //Скалярное произведение
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            Cmatrix[i][j] = 0;
            for (int k = 0; k < M; k++) {
                Cmatrix[i][j] += Amatrix[i][k] * Bmatrix[k][j];
            }
        }
    }

    //Вывод
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Cmatrix[i][j] << ' ';
        }
        cout << endl;
    }

}
