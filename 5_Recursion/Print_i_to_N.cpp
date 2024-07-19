#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   //similar to for loop
   // Base Condition.
   if(i>n) return;
   cout<<i<<endl;

   // Function call to print i till i increments to n.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}

//my try
#include<iostream>
using namespace std;
void rec(int i,int n){ //like a loop

//analogus to for loop printing
    if(i>n)
    return;
    
    cout<<i<<endl;
    rec(i+1,n);
}
int main()
{
    int n;
    cout<<"Enter NUmber of elements"<<endl;
    cin>>n;
    rec(1,n);
    return 0;
}