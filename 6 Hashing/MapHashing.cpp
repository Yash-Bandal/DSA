#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements" << endl;
    for (size_t i{0}; i < n; i++)
    {
        cin >> arr[i];
    }
    // prefetch
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // Display Map
    for (auto it : mpp)
    {
        cout << it.first << " :" << it.second << endl;
    }
    /*
0 :1
1 :3
4 :2
6 :2
7 :2*/

    cout << "Enter queries" << endl;
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter Number ";
        int number;
        cin >> number;
        // fetch:
        cout << mpp[number] << endl;
    }
    return 0;
}

//string map

#include <bits/stdc++.h>
using namespace std;

int main()
{
   string str;

    cout << "Enter String" << endl;
    cin>>str;
  
    // prefetch
    unordered_map<char, int> mpp;
    // for(auto it:str)  //dont use auto i
    // {
    //     // mpp[str[i]]++;  //here we are using range for so i not str[i]..so use 'it' not i for ess confusion
    //       mpp[it]++;
    // }

    for(int i=0;i<str.length();i++)
    {
        mpp[str[i]]++;
    }

    // Display Map
    for (auto it : mpp)
    {
        cout << it.first << " :" << it.second << endl;
    }

    cout << "Enter queries" << endl;
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter Char ";
        char c;
        cin >> c;
        // fetch:
        cout << mpp[c] << endl;
    }
    return 0;
}


//Main 

#include <bits/stdc++.h>
using namespace std;
 
void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;
 
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
 
    // Traverse through map and print frequencies
    for (auto it : map)
        cout <<it.first << " :" << it.second << endl;
}
 
int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}


//Leetcode question...
/*
When frequency question asked and we need to check frquecy...

dont 
      for(auto it : mpp){
            if(it.second==1){
                distStr.push_back(it.first);
            }
      
        }
   bcoz order is not maintainded in map and unordered map

   so iteratie throught the main arr or vec
   the count is stored in mpp[it]
   or mpp[arr[i]]


   read the question..if size exceeds 2 then return ""
   or directly acces the index k-1 and return the ele
   
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mpp;
        vector<string> distStr;
        
        // Count the frequency of each string
        for (const auto& str : arr) {
            mpp[str]++;
        }
        
        // Collect distinct strings in the order of their appearance
        for (const auto& str : arr) {
            if (mpp[str] == 1) {
                distStr.push_back(str);
            }
        }
        
        // Print the contents of distStr
        cout << "Distinct Strings: ";
        for (const auto& str : distStr) {
            cout << str << " ";
        }
        cout << endl;
        
        // Return the k-th distinct string if it exists
        if (k <= distStr.size()) {
            return distStr[k - 1];
        } else {
            return "";
        }
    }
};

int main() {
    Solution solution;
    vector<string> arr1 = {"d", "b", "c", "b", "c", "a"};
    int k1 = 2;
    cout << "Test Case 1: " << solution.kthDistinct(arr1, k1) << endl; // Output: "a"
    
    vector<string> arr2 = {"aaa", "aa", "a"};
    int k2 = 1;
    cout << "Test Case 2: " << solution.kthDistinct(arr2, k2) << endl; // Output: "aaa"
    
    vector<string> arr3 = {"a", "b", "a"};
    int k3 = 3;
    cout << "Test Case 3: " << solution.kthDistinct(arr3, k3) << endl; // Output: ""
    
    return 0;
}
