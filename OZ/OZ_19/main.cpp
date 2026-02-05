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

tuple<int*, int, int> binary_insertion_sort(int* arr, int size) {
    int comparisons = 0;
    int permutations = 0;
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = (left + right) / 2;
            comparisons++;
            if (arr[mid] <= key) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        for (int j = i; j > left; --j) {
            arr[j] = arr[j - 1];
            permutations++;
        }
        arr[left] = key;
    }
    return {arr, comparisons, permutations};
}

int main() {
    auto [arr, size] = gen_array();
    cout << "Array size: " << size << endl;
    cout << "Not sorted array:" << endl;
    printArray(arr, size);
    auto [sorted_arr, comparisons, permutations] = binary_insertion_sort(arr, size);
    cout << "Sorted array:" << endl;
    printArray(sorted_arr, size);
    cout << "C(n) (Comparisons): " << comparisons << endl;
    cout << "M(n) (Permutations): " << permutations << endl;
    return 0;
}
