#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    const int N = 9;
    int a[N][N];

    cout << "Матрица 9x9:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 101;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int S1 = 0, S2 = 0, S3 = 0, S4 = 0;

    for (int j = 0; j < N; j++) {
        S1 += a[0][j];
        S1 += a[8][j];
    }
    for (int i = 1; i <= 7; i++) {
        S1 += a[i][0];
        S1 += a[i][8];
    }

    for (int i = 0; i < N; i++) {
        S2 += a[i][i];
    }
    for (int i = 0; i < N; i++) {
        if (i != 4) {
            S2 += a[i][8 - i];
        }
    }

    S3 += a[0][4];
    S3 += a[1][3] + a[1][4] + a[1][5];
    S3 += a[2][2] + a[2][3] + a[2][4] + a[2][5] + a[2][6];
    S3 += a[3][1] + a[3][2] + a[3][3] + a[3][4] + a[3][5] + a[3][6] + a[3][7];
    for (int j = 0; j < 9; j++) S3 += a[4][j];
    S3 += a[5][1] + a[5][2] + a[5][3] + a[5][4] + a[5][5] + a[5][6] + a[5][7];
    S3 += a[6][2] + a[6][3] + a[6][4] + a[6][5] + a[6][6];
    S3 += a[7][3] + a[7][4] + a[7][5];
    S3 += a[8][4];

    for (int j = 0; j < 9; j++) S4 += a[0][j];
    for (int j = 1; j < 8; j++) S4 += a[1][j];
    for (int j = 2; j < 7; j++) S4 += a[2][j];
    for (int j = 3; j < 6; j++) S4 += a[3][j];
    S4 += a[4][4];
    for (int j = 3; j < 6; j++) S4 += a[5][j];
    for (int j = 2; j < 7; j++) S4 += a[6][j];
    for (int j = 1; j < 8; j++) S4 += a[7][j];
    for (int j = 0; j < 9; j++) S4 += a[8][j];

    cout << "\nСуммы:\n";
    cout << "S1 (контур): " << S1 << endl;
    cout << "S2 (диагонали): " << S2 << endl;
    cout << "S3 (ромб): " << S3 << endl;
    cout << "S4 (песочные часы): " << S4 << endl;

    return 0;
}
