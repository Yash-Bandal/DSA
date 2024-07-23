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
//O(n)  TC

//Less tc


#include<iostream>
using namespace std;
int Pow(int a,int n){


     if(n==1){
        return a;
    }
     else if(n==0){
        return 1;
    }

    int temp=Pow(a,n/2);

    if(n%2==1){  //eg 2 power 17..calculate till 2 power 16 using above and multiply a
     return temp*temp*a;
    }
    else return temp*temp;

   
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
