//Bubble Sort-easiest but high TC

/*Push Max element to last each timr
swap arr[j] and arr[j+1]


note : the last element is sorted after every iteration..
thus skip it 
so run the loop j=0 j<n-i-1...so that reverse 7 6 5 4 3 2 1 times size is considered
*/
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int> &arr, int n)
{
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){   //first iteration n-1 7 times..lastelement is sorted
        if(arr[j]>arr[j+1])    //so for second iteration skip the last one..
        swap(arr[j+1],arr[j]);  //so -i-1=6 5 4 3 2 1 0...for j loop iterations
    }
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
    bubbleSort(arr, n);
    cout<<"After Sorting :"<<endl;
    printArray(arr, n);
    return 0;
}

// void swap(vector<int>& arr, int i, int j) {
//     int temp = arr[i];
//     arr[i] = arr[min];
//     arr[min] = temp;
// }

//-x-x-x-x-x-x-x-x--x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x

//Observe pattern every time the j loop goes from 0 to n-1
//thus set i start from i=n-1 to i>=1
// j =0 to j<=i
//if we run j j+1 at last we will reach unknown index..and we dont need the last le so iterate till i-1

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 0; j <= i-1 ; j++) //or j<i
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j + 1], arr[j]);
        }
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
    bubbleSort(arr, n);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}







//Bubble sort has O n square TC..but with optimization and reducing the itearations over swapped it can be best O(n)
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    bool swapped;
    for (int i = n - 1; i >= 1; i--)
    {
        swapped = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
        cout << "runs" << endl;
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
    // vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    int n = arr.size();
    bubbleSort(arr, n);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}
