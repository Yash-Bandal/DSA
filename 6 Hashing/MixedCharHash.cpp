#include <bits/stdc++.h>
using namespace std;

int main() {

cout<<"Enter String of Mixed CHars"<<endl;
    string s;
    cin >> s;

    //precompute:
    int hash[256] = {0};   //A has 65 ascii..so count stored at 65 small a at 96..behind 65 empty arr
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;    //autocast charac to asci num
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
