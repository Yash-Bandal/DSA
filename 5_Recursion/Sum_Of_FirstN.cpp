#include<iostream>
using namespace std;
int sumRec(int N)
{ 
    if(N==1){  //base think of smallest sumRec possibility Input N=1
    return 1;
    }

int temp=sumRec(N-1);  //smalles subproblem closes to N is N-1
return (temp+N);   //sumRec(N-1)+N is ans
}
int main()
{
    int N;
    cout<<"Enter Number untill where U want sum"<<endl;
    cin>>N;
    int res=sumRec(N);
    cout<<"The sum of first "<<N<<" Natural Numbers is :"<<res<<endl;
    return 0;
  
}
