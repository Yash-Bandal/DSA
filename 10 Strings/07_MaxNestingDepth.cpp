class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0; //dont use INT_MIN as if no '()' in str ..return 0

        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s[i]) && s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                maxCnt = max(maxCnt, cnt);
                cnt--;
            }
        }
        return maxCnt;
    }
};
//
eg s="25+06"..op=0
eg s=(())((()))..when we get )..cnt--..but before decrementing maxCnt
