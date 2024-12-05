class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> mppS;
        unordered_map<char, int> mppT;

        // Count the frequency of characters in both strings
        for (int i = 0; i < s.length(); i++) {
            mppS[s[i]]++;
            mppT[t[i]]++;
        }

        for (auto& entry : mppS) {
            if (mppT[entry.first] !=
                entry
                    .second) { // that is chk cnt of entry in mppT != mppS count
                // it may seem .first .second..but both point to counts ..
                // mppT[entry.first] =mppT count value
                return false;
            }
        }
        return true;
    }
};
