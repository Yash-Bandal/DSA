
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str1="123 45 66";
    char str2[] = "123 45 66";

    cout<<stoi(str1)<<endl; //output 123
    cout<<atoi(str2)<<endl; //output 123
    /*
    stoi string to int works on strings
    atoi ascii to int works on charac array
    both stop when non digi value eg ' ' is concurred
    */
    char c = '1';
    int converted = c-'0';
    cout<<converted<<endl;

    return 0;
}
