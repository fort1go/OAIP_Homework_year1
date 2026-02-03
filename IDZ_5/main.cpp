#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int matrix[N][M];

    //Рандомная матрица
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         matrix[i][j] = rand() % 10;
    //     }
    // }

    //Ввод матрицы вручную
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    //Счётчик ариф. прогр.
    int count = 0;
    for (int i = 0; i < N; i++) {
        bool isAP = true;
        int diff = matrix[i][1] - matrix[i][0];
        for (int j = 1; j < M; j++) {
            if (matrix[i][j] - matrix[i][j-1] != diff) {
                isAP = false;
                break;
            }
        }
        if (!isAP) {
            count++;
        }
    }

    //Вывод матрицы
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << count << endl;
    return 0;
}
