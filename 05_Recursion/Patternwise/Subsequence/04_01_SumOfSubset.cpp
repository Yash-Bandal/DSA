//see notebook for visualization and tree
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(vector<int>& dS) {
    for (auto it : dS) {
        cout << it << " ";
    }
    cout << endl;
}
void printS(int i, vector<int>& dS, int s, vector<int>& arr, int target) {
    if (i == arr.size()) {
        if (s == target) {
            print(dS);
        }
        return;
    }
    // Include
    dS.push_back(arr[i]); //0 1 2 2..all indices tree 
    s += arr[i];
    printS(i + 1, dS, s, arr, target);

    // exclude
    dS.pop_back();
    s -= arr[i];
    printS(i + 1, dS, s, arr, target);
}
int main() {
    vector<int> arr = {1, 2, 1};
    int target = 2;
    vector<int> ds;
    printS(0, ds, 0, arr, target);

    return 0;
}

/*
output :
1 1 
2 

*/

//======================================
//Print only one seq

//1 Not recommended GLOBAL VAR bool..as it gives seg fault
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool flag = false;
void print(vector<int>& dS) {
    for (auto it : dS) {
        cout << it << " ";
    }
    cout << endl;
}
void printS(int i, vector<int>& dS, int s, vector<int>& arr, int target) {
    if (i == arr.size() && flag == false) {
        if (s == target) {
            flag = true;
            print(dS);
        }
        return;
    }
    // Include
    dS.push_back(arr[i]); //0 1 2 2..all indices tree 
    s += arr[i];
    printS(i + 1, dS, s, arr, target);

    // exclude
    dS.pop_back();
    s -= arr[i];
    printS(i + 1, dS, s, arr, target);
}
int main() {
    vector<int> arr = {1, 2, 1};
    int target = 2;
    vector<int> ds;
    printS(0, ds, 0, arr, target);

    return 0;
}

//OR

int cnt = 0;
void print(vector<int>& dS) {
    for (auto it : dS) {
        cout << it << " ";
    }
    cout << endl;
}
void printS(int i, vector<int>& dS, int s, vector<int>& arr, int target) {
    if (i == arr.size() && cnt ==0) {
        if (s == target) {
          cnt = 1;
            print(dS);

        }
        return;
    }
/*
OP:
1 1 
Segmentation fault

*/



//Correct functional way- bool function type
//To print single ele..Stop after 1 recursion and avoid future recursion calls
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<int>& dS) {
    for (auto it : dS) {
        cout << it << " ";
    }
    cout << endl;
}
bool printS(int i, vector<int>& dS, int s, vector<int>& arr, int target) {
    if (i == arr.size()) {
        //condition satisfied
        if (s == target) {
            print(dS);
            return true;
        }
            //not satisfied
        else{
        return false;
        }
    }
    // Include
    dS.push_back(arr[i]); //0 1 2 2..all indices tree 
    s += arr[i];
    if(printS(i + 1, dS, s, arr, target) == true){
        return true;
    }

    // exclude
    dS.pop_back();
    s -= arr[i];
    if(printS(i + 1, dS, s, arr, target) == true){
        return true;
    }
    
    return false;
    
}
int main() {
    vector<int> arr = {1, 2, 1};
    int target = 2;
    vector<int> ds;
    printS(0, ds, 0, arr, target);

    return 0;
}
/*
op :
1 1


NO SEG FAULT
*/
