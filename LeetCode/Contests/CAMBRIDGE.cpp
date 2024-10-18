// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
//  string s1;
 string ip;
 cin>>ip;
 string res="";
 for(auto c : ip){
     if(c !='C' && c !='A' && c !='M' && c !='B' && c !='R' && c !='I' && c !='D' && c !='G' && c !='E' )
     {a
        res+=c;
     }
     
 }
 
 for(auto ch : res){
     cout<<ch<< " ";
 }

    return 0;
}
