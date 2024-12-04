class Solution {
public:
    bool isPalindrome(string s) {
        // Main goal...make a unified string..nd use 2 ptrs to chk frm left to
        // right eql or not

        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (!isalnum(s[left])) // skip unncecessary : / ..other symbols that
                                   // are neither num and nor alpha
                left++;
            else if (!isalnum(s[right]))
                right--;
            else if (tolower(s[left]) != tolower(s[right]))
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

/*
isialpha(c) - true if letter/alphabet
isdigit(c) - true if c is digit '10'
isalnum(c) - true if above both..satisgy above both


*/
