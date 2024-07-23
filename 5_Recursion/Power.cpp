#include<iostream>
using namespace std;
int Pow(int a,int n){

     if(n==1){
        return a;
    }
     else if(n==0){
        return 1;
    }

    int temp=Pow(a,n-1);
    return a*temp;
}
int main()
{
    int a,n;
    cout<<"Enter base and power"<<endl;
    cin>>a>>n;
    cout<<"The Answer is :";
    cout<<Pow(a,n)<<" ";
    return 0;
}