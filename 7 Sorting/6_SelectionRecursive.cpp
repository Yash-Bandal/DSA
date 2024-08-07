#include <bits/stdc++.h>
using namespace std;

// Recursive function to sort the array using selection sort
void selectionSortRecursive(vector<int>& arr, int n, int index = 0) {
    // Base case: when the entire array is sorted
    if (index == n - 1) {
        return;
    }

    // Find the minimum element in the unsorted part of the array
    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the found minimum element with the first element
    if (minIndex != index) {
        swap(arr[minIndex], arr[index]);
    }

    // Recursively sort the remaining part of the array
    selectionSortRecursive(arr, n, index + 1);
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    int n = arr.size();
    selectionSortRecursive(arr, n);
    cout << "After Sorting:" << endl;
    printArray(arr);
    return 0;
}
