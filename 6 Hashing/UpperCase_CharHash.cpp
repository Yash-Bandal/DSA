#include <bits/stdc++.h>
using namespace std;

int main() {

cout<<"Enter string of chars UpperCase"<<endl;
    string s;
    cin >> s;

    //precompute:
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'A']++;
    }
cout<<"Enter queries"<<endl;
    int q;
    cin >> q;
    while (q--) {
        cout<<"Enter char"<<endl;
        char c;
        cin >> c;
        // fetch:
        cout << hash[c - 'A'] << endl;
    }
    return 0;
}
