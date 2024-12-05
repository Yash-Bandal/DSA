class Solution {
public:
    string largestOddNumber(string snum) {
        for (int i = snum.length() - 1; i >= 0; i--) {
            if ((snum[i]-'0') % 2 == 1) {
                return snum.substr(0, i + 1);
            }
        }
        return "";
    }
};

/*
eg 2458764

245876
24587

*/
