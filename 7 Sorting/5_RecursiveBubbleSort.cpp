
// bubbleRec sort
#include <bits/stdc++.h>
using namespace std;

void bubbleRecSort(vector<int> &arr, int n)
{
    // base case...if single element that is index =0
    // either if index passed check if endIndex==0
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleRecSort(arr, n - 1);
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    int n = arr.size();
    bubbleRecSort(arr, n);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}
