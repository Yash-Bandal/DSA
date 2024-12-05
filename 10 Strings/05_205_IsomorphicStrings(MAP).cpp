class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mppS;
        unordered_map<char, int> mppT;

        for (int i = 0; i < s.length(); i++) {
            //if == then element check if not present in map
            //if != then element check if present in map
            if (mppS.find(s[i]) == mppS.end()) {
                mppS[s[i]] = i;  //{e : 0 , g :1}
            }

            if (mppT.find(t[i]) == mppT.end()) {
                mppT[t[i]] = i; //{a : 0 , d :1}
            }
            if (mppS[s[i]] != mppT[t[i]]) { //{1 != 1 ..?} ..or 0!=0..?
                return false;  //dont return true here and down false..wrong op
            }
        }
        return true;
    }
};
