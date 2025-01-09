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
