#include<iostream>
using namespace std;

// 0 1 2 3 4     0 1 2 3 4
//[1 2 3 4 5 ]==[5 4 3 2 1]

void rev(int arr[],int s,int e){
    
    int lastIndex=e;
    if( s>=e){
        return ;
    }
    
    
        swap(arr[s],arr[e]);
    
        rev(arr,s+1,e-1);


}
int main()
{
    int arr[5]={1,2,3,4,5};
    rev(arr,0,4);

    for(int i=0;i<5;i++)
    {
            cout<<arr[i]<<" ";
    }

    return 0;
}
