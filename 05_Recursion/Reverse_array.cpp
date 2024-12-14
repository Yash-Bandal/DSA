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


//o(n/2)
#include<iostream>
using namespace std;

// 0 1 2 3 4     0 1 2 3 4
//[1 2 3 4 5 ]==[5 4 3 2 1]

void rev(int arr[],int i,int n){  //n=size
    
    if(i>=n/2){
        return ;
    }
    swap(arr[i],arr[n-i-1]);   //it forstart i=1 end =n-i-1=3  ..
    rev(arr,i+1,n);
}
int main()
{
    int arr[5]={1,2,3,4,5};
    rev(arr,0,5);

    for(int i=0;i<5;i++)
    {
            cout<<arr[i]<<" ";
    }

    return 0;
}
