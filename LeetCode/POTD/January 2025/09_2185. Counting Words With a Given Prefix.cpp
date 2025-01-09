class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (auto it : words) {
            if (it.find(pref) == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}; 

//=====================================================================

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = 0;
        int n = pref.length();
        for (const string& w : words) {
            if (w.size() >= n && w.compare(0, n, pref) == 0) {
                c++;
            }
        }
        return c;
    }
};
