// insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSortRec(vector<int> &arr, int n,int beginIndex)
{
    //base case i==n 
    //simply beginIndex is i
    if(beginIndex==n){
        return;
    }
    int j=beginIndex;

        //iterate back with while checking greater num behnd
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;  //check and iterate back
        }
        //stop when smaller num arrive and i++ happens
        insertionSortRec(arr,n,beginIndex+1);
    
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
    insertionSortRec(arr, n,0);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}



//brginIndex visualize as i loop



// insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSortRec(vector<int> &arr, int n,int i)
{
    //base case i==n 
    //simply i is i
    if(i==n){
        return;
    }
    int j=i;

        //iterate back with while checking greater num behnd
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;  //check and iterate back
        }
        //stop when smaller num arrive and i++ happens
        insertionSortRec(arr,n,i+1);
    
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
    insertionSortRec(arr, n,0);
    cout << "After Sorting :" << endl;
    printArray(arr, n);
    return 0;
}

