/*
Simply remember old non rec selectionSort

we here eliminate outer loop


let j=i here and resemble i as beginIndex
perform the outer loop as beginIndex recursion
*/


#include<bits/stdc++.h>
using namespace std;

// Recursive function to sort the array using selection sort
void selectionSortRecursive(vector<int> &arr, int n, int beginIndex)
{
    // base case...index reach last
    if (beginIndex == n - 1)
    {
        return;
    }
    int minIndex = beginIndex;
    for (int i = beginIndex+1; i < n; i++)
    {

        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[beginIndex];
    arr[beginIndex] = temp;

    // Recursively sort the remaining part of the array
    selectionSortRecursive(arr, n, beginIndex + 1);
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    int n = arr.size();
    selectionSortRecursive(arr, n, 0);
    cout << "After Sorting:" << endl;
    printArray(arr);
    return 0;
}
