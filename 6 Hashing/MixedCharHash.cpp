#include <bits/stdc++.h>
using namespace std;

int main() {

cout<<"Enter String of Mixed CHars"<<endl;
    string s;
    cin >> s;

    //precompute:
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }
    cout<<"Enter query count"<<endl;

    int q;
    cin >> q;
    while (q--) {
        cout<<"Enter Char ";
        char c;
        cin >> c;
        // fetch:
        cout << hash[c] << endl;
    }
    return 0;
}
