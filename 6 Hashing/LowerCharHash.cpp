#include <bits/stdc++.h>
using namespace std;

int main() {

cout<<"Enter string of chars lowercase"<<endl;
    string s;
    cin >> s;

    //precompute:
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }
cout<<"Enter queries"<<endl;
    int q;
    cin >> q;
    while (q--) {
        cout<<"Enter char"<<endl;
        char c;
        cin >> c;
        // fetch:
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}


/*See leetcode 3016*/
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterFreq(26, 0);
        for (char c : word) {
            letterFreq[c - 'a']++;
        }
        
        sort(letterFreq.rbegin(), letterFreq.rend());
        
        int totalPresses = 0;
        for (int i = 0; i < 26; i++) {
            if (letterFreq[i] == 0) break;
            totalPresses += (i / 8 + 1) * letterFreq[i];
        }
        
        return totalPresses;
    }
};
