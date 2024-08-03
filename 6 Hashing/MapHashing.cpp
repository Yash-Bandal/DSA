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
