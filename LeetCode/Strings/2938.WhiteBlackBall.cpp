//See last page of DSA 2 book
class Solution {
public:
    long long minimumSteps(string s) {
        // The total swaps required will be the sum of all the 0s each 1 has to
        // move over.
        // observe each 1 has to jump over 0s count
        // eg if 100 one 1 jumps 2 0s ..thus ans 2
        // eg if 10101 ..first 1 jumps 1 0s and 2nd 1 2 0s..thus 3

        int n = s.length();
        long long whiteCount = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                res += whiteCount;
            } else if (s[i] == '1') {
                whiteCount++;
            }
        }
        return res;
    }
};


// Dry Run for input "10101100":
// Iteration 1 (i = 0):
// s[0] = '1', whiteCount = 1, res = 0
//
// Iteration 2 (i = 1):
// s[1] = '0', res += whiteCount (res = 1), whiteCount = 1
//
// Iteration 3 (i = 2):
// s[2] = '1', whiteCount = 2, res = 1
//
// Iteration 4 (i = 3):
// s[3] = '0', res += whiteCount (res = 3), whiteCount = 2
//
// Iteration 5 (i = 4):
// s[4] = '1', whiteCount = 3, res = 3
//
// Iteration 6 (i = 5):
// s[5] = '1', whiteCount = 4, res = 3
//
// Iteration 7 (i = 6):
// s[6] = '0', res += whiteCount (res = 7), whiteCount = 4
//
// Iteration 8 (i = 7):
// s[7] = '0', res += whiteCount (res = 11), whiteCount = 4
//
// Final Result: res = 11 (minimum number of swaps required)
