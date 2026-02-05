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

tuple<int*, int, int> selection_sort(int arr[], int size) {
    int comparisons = 0;
    int permutations = 0;
    for (int left = 0; left < size - 1; left++) {
        int min_index = left;
        for (int i = left + 1; i < size; i++) {
            comparisons++;
            if (arr[i] < arr[min_index]) {
                min_index = i;
            }
        }
        if (min_index != left) {
            swap(arr[left], arr[min_index]);
            permutations++;
        }
    }
    return {arr, comparisons, permutations};
}

int main() {
    auto [arr, size] = gen_array();
    cout << "Array size: " << size << endl;
    cout << "Not sorted array:" << endl;
    printArray(arr, size);
    auto [sorted_arr, comparisons, permutations] = selection_sort(arr, size);
    cout << "Sorted array:" << endl;
    printArray(sorted_arr, size);
    cout << "C(n) (Comparisons): " << comparisons << endl;
    cout << "M(n) (Permutations): " << permutations << endl;
    return 0;
}
