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
        cout << "Enter Char ";
        int number;
        cin >> number;
        // fetch:
        cout << mpp[number] << endl;
    }
    return 0;
}
