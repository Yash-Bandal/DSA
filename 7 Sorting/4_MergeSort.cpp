// merge sort
//Lowest TC O(N log N)

#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    
    while(left<=mid && right<=high){

        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }
        
    while(left<=mid ){

            temp.push_back(arr[left]);
            left++;

    }
        
    while(right<=high){
            temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++){

        arr[i]=temp[i-low];
    }
    

}
void mergeSort(vector<int> &arr,int low ,int high){
    if(low == high){ //that is single element 
        return ;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void getFunc(vector<int> &arr, int n)
{
mergeSort(arr,0,n-1);

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
    getFunc(arr, n);
    cout<<"After Sorting :"<<endl;
    printArray(arr, n);
    return 0;
}
/*
When copying temp back to arr, you want:
low can change if some user wants to sort from middle only and keep forst elem as it is

eg if low =3  user specified... we can have corect index with i-low
arr[0] = temp[0 - 0] which is 0
arr[1] = temp[1 - 0] which is 1
arr[2] = temp[2 - 0] which is 2
and so on...
By doing temp[i - low], you ensure you are copying from the
correct index of temp back to the corresponding index in arr.
*/
