/*
1. Initialize minIndex with i every iteration to consider first ele sorted all time
2 compare arr[j] with arr[mninInd]  //not with arr[i] as i is same for j loop but minIndex is updateed everytime
3 set minIndex with the smallest index minInd=j
4 swap arr[j] and arr[minInd]
*/


//Passing A Vector
// selection sort
#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int> &arr, int n)  //Pass by reference all time  &arr or arr[]
{  

    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
           
        }
         if (minInd != i)
                swap(arr[minInd], arr[i]);
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
    selectionSort(arr, n);
    cout<<"After Sorting :"<<endl;
    printArray(arr, n);
    return 0;
}

// void swap(vector<int>& arr, int i, int j) {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }


//-----------------------------------------------------------------------------
//Passing an array
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minInd = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        if (minInd != i)
            swap(arr[minInd], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
TC=O n^2
