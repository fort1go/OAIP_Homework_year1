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

tuple<int*, int, int> cocktail_sort(int* arr, int size) {
    int comparisons = 0;
    int permutations = 0;
    int left = 0, right = size - 1;
    while (left < right) {
        bool swapped = false;
        for (int i = left; i < right; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                permutations++;
                swapped = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            comparisons++;
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                permutations++;
                swapped = true;
            }
        }
        left++;
        if (!swapped) break;
    }
    return {arr, comparisons, permutations};
}

int main() {
    auto [arr, size] = gen_array();
    cout << "Array size: " << size << endl;
    cout << "Not sorted array:" << endl;
    printArray(arr, size);
    auto [sorted_arr, comparisons, permutations] = cocktail_sort(arr, size);
    cout << "Sorted array:" << endl;
    printArray(sorted_arr, size);
    cout << "C(n) (Comparisons): " << comparisons << endl;
    cout << "M(n) (Permutations): " << permutations << endl;
    return 0;
}
