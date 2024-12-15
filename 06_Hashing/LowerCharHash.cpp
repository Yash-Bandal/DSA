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

/*
The core idea behind solving this problem lies in optimizing the key mapping to minimize the total number of key presses required to type a given word. The intuition stems from the observation that in an optimal mapping, the most frequently occurring letters should be assigned to keys that require the least number of presses.

Consider a standard phone keypad with 8 available keys (2-9). Each key can be pressed multiple times to access different letters. For instance, pressing a key once might give you the first letter, twice for the second letter, and so on. With this in mind, the optimal strategy would be to assign the 8 most frequent letters to single presses across the 8 keys, the next 8 most frequent letters to double presses, and continue this pattern.

This approach naturally leads to a greedy algorithm. By sorting the letters based on their frequency in descending order, we can ensure that the most common letters are assigned to the easiest-to-access positions on the keypad.
*/
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/discuss/5593444/O(n)-or-Greedy-or-Heap-or-Java-or-C%2B%2B-or-Python-or-Go-or-Rust-or-JavaScript
