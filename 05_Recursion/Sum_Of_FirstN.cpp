//basic
#include<bits/stdc++.h>
using namespace std;
 void solve(int N) {
    int sum = N * (N + 1) / 2;
    cout<<"The sum of the first "<<N<<" numbers is: "<<sum<<endl;
  }
 int main() {

    solve(5);
    solve(6);
  }
 

//============================================================================
//Nishant Chahar
#include<iostream>
using namespace std;
int sumRec(int N)
{ 
    if(N==1){  //base think of smallest sumRec possibility Input N=1
    return 1;
    }
int temp=sumRec(N-1);  //smallest subproblem closes to N is N-1
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

//====================================================================


//Parametrized..ake u forward
#include<bits/stdc++.h>
using namespace std;

void func(int i, int sum){
   
   // Base Condition.
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }

   // Function call to increment sum by i till i decrements to 1.
   func(i-1,sum+i);

}

int main(){
  
  // Here, let’s take the value of n to be 3.
  int n = 3;
  func(n,0);
  return 0;

}
