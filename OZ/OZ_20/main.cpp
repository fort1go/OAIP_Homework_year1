#include <iostream>
using namespace std;

pair<int*, int> gen_array() {
    int size = rand() % 100 + 20;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return {arr, size};
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

tuple<int*, int, int> bauble_sort(int* arr, int size) {
    int comparisons = 0;
    int permutations = 0;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                permutations++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return {arr, comparisons, permutations};
}

int main() {
    auto [arr, size] = gen_array();
    cout << "Array size: " << size << endl;
    cout << "Not sorted array:" << endl;
    printArray(arr, size);
    auto [sorted_arr, comparisons, permutations] = bauble_sort(arr, size);
    cout << "Sorted array:" << endl;
    printArray(sorted_arr, size);
    cout << "C(n) (Comparisons): " << comparisons << endl;
    cout << "M(n) (Permutations): " << permutations << endl;
    return 0;
}
