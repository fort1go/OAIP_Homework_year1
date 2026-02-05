#include <iostream>
using namespace std;

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

tuple<int*, int, int> insertion_sort(int* arr, int size) {
    int comparisons = 0;
    int permutations = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                permutations++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return {arr, comparisons, permutations};
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

pair<int, int> test(int arr[], int size, tuple<int*, int, int> (*func)(int arr[], int size)) {
    printArray(arr, size);
    auto [sorted_array, comparisons, permutations] = func(arr, size);
    printArray(sorted_array, size);
    cout << "n: " << size << endl;
    cout << "C(n): " << comparisons << endl;
    cout << "M(n): " << permutations << endl;
    return {comparisons, permutations};
}

int main() {
    int arr[10] = {1, 45, 2, 32, 423, 3, 5, 13, 30, 100};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    cout << "selection_sort" << endl;
    auto [selection_sort_comparisons, selection_sort_permutations] = test(new int[10]{1, 45, 2, 32, 423, 3, 5, 13, 30, 100}, size, selection_sort);
    cout << "insertion_sort" << endl;
    auto [insertion_sort_comparisons, insertion_sort_permutations] = test(new int[10]{1, 45, 2, 32, 423, 3, 5, 13, 30, 100}, size, insertion_sort);
    cout << "binary_insertion_sort" << endl;
    auto [binary_insertion_sort_comparisons, binary_insertion_sort_permutations] = test(new int[10]{1, 45, 2, 32, 423, 3, 5, 13, 30, 100}, size, binary_insertion_sort);
    cout << "bauble_sort" << endl;
    auto [bauble_sort_comparisons, bauble_sort_permutations] = test(new int[10]{1, 45, 2, 32, 423, 3, 5, 13, 30, 100}, size, bauble_sort);
    cout << "cocktail_sort" << endl;
    auto [cocktail_sort_comparisons, cocktail_sort_permutations] = test(new int[10]{1, 45, 2, 32, 423, 3, 5, 13, 30, 100}, size, cocktail_sort);

        cout << "\n========== Analysis ==========\n";
    cout << "The best algorithm for comparisons:\n";

    int best_comp = selection_sort_comparisons;
    string best_comp_name = "selection_sort";

    if (insertion_sort_comparisons < best_comp) {
        best_comp = insertion_sort_comparisons;
        best_comp_name = "insertion_sort";
    }
    if (binary_insertion_sort_comparisons < best_comp) {
        best_comp = binary_insertion_sort_comparisons;
        best_comp_name = "binary_insertion_sort";
    }
    if (bauble_sort_comparisons < best_comp) {
        best_comp = bauble_sort_comparisons;
        best_comp_name = "bauble_sort";
    }
    if (cocktail_sort_comparisons < best_comp) {
        best_comp = cocktail_sort_comparisons;
        best_comp_name = "cocktail_sort";
    }

    cout << best_comp_name << " (" << best_comp << " comparisons)\n\n";

    cout << "The best algorithm for permutations:\n";

    int best_perm = selection_sort_permutations;
    string best_perm_name = "selection_sort";

    if (insertion_sort_permutations < best_perm) {
        best_perm = insertion_sort_permutations;
        best_perm_name = "insertion_sort";
    }
    if (binary_insertion_sort_permutations < best_perm) {
        best_perm = binary_insertion_sort_permutations;
        best_perm_name = "binary_insertion_sort";
    }
    if (bauble_sort_permutations < best_perm) {
        best_perm = bauble_sort_permutations;
        best_perm_name = "bauble_sort";
    }
    if (cocktail_sort_permutations < best_perm) {
        best_perm = cocktail_sort_permutations;
        best_perm_name = "cocktail_sort";
    }

    cout << best_perm_name << " (" << best_perm << " permutations)\n\n";

    // Вывод наблюдений
    cout << "📌 Notes:\n";
    if (best_perm_name == "selection_sort") {
        cout << "- Selection sort made fewer permutations, because\n";
        cout << "  it puts the elements in place in one exchange.\n";
    }
    if (best_comp_name == "binary_insertion_sort") {
        cout << "- Binary insertion used fewer comparisons thanks to\n";
        cout << "  binary search position.\n";
    }
    if (insertion_sort_permutations == bauble_sort_permutations &&
        bauble_sort_permutations == cocktail_sort_permutations) {
        cout << "- The bauble sort, shaker sort, and insertion sort made the same number of \n";
        cout << "  permutations—this is the number of inversions in the array.\n";
    }
    return 0;
}
