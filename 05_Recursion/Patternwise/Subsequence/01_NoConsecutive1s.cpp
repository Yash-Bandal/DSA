#include<bits/stdc++.h>
using namespace std;
//its a character array ..with k size of each string and n = arr length
void generateStr(char str[],int k,int n){
    //base cases
    if(k == n){
        str[n] = '\0';
        cout<<str<<" ";
        return; //dont forget this
    }
    //check 1 _?_
    if(str[n-1] == '1'){
        str[n] = '0';
        generateStr(str,k,n+1);  //magic
    }
    
     //check 0 _?_
    if(str[n-1] == '0'){
        str[n] = '0';
        generateStr(str,k,n+1);
        
        str[n] = '1';
        generateStr(str,k,n+1);
    }
}
void generateString(int k){
    if(k <= 0){
        return;
    }
    char str[k+1];  //last '\0'
    str[0] = '0';
    generateStr(str,k,1);
    /*
    000\0
    001\0
    010\0
    */
    
    str[0] = '1';
    generateStr(str,k,1);
    /*
    100\0
    101\0
    */
}
int main(){
    int k=3;
    generateString(k);
    return 0;
}

/*
question is to  not get consecutive 1s..eg 011 and all
thus...
if we have 0 as start we can have next 00 or 01 and
when we have 1 as start we can only have 0  ie 10..not 11

..base case
check previos and define for smallest str length possible..ie length 2

define cases for 3strs..and magic recursion..
stop when k == n ..desired reached
11

00
01



thus 
1 recursion op 
000\0
001\0
010\0

100\0
101\0


backslash 0..we pass initially 0 nd 1 at start positions


*/
