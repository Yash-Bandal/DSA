// insertion sort
/*Place element while comparing backwards in its correct position*/
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{

//Go forwared iterate full array with for i loop first

    for (size_t i{0}; i <= n-1; i++)  //i<n
    {
        int j = i;
        //iterate back with while checking greater num behnd
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;  //check and iterate back
        }
        //stop when smaller num arrive and i++ happens
    }
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
    insertionSort(arr, n);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}
//T.C =O(n^2)
//S.C=O(1)
