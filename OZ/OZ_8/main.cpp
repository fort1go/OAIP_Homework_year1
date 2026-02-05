#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int N = 7;
    double a[N][N];
    srand(time(0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = -1.0 + 2.0 * rand() / RAND_MAX;

    int max_i = 0, min_j = 0;
    double mx = a[0][0], mn = a[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (a[i][j] > mx) { mx = a[i][j]; max_i = i; }
            if (a[i][j] < mn) { mn = a[i][j]; min_j = j; }
        }

    double s = 0;
    for (int k = 0; k < N; k++)
        s += a[max_i][k] * a[k][min_j];

    cout << s << endl;
    return 0;
}
