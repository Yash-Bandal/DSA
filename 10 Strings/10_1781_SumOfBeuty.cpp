//TC= O(n*m)
class Solution {
public:
    int beautySum(string s) {
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++; // counting the frequency of each character
                // reset for every substring
                int mfreq = INT_MIN;
                int lfreq = INT_MAX;
                // Finding most frequent and least frequent chracter
                for (auto it : mpp) {
                    mfreq = max(mfreq, it.second);
                    lfreq = min(lfreq, it.second);
                }
                ans += (mfreq - lfreq);
            }
        }
        return ans;
    }
};
