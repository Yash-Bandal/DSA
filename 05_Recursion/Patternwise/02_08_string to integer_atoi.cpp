//brute
class Solution {
public:
    int myAtoi(string s) {
        bool flag = false; // mark flag true when number is digit
        long long ans = 0;
        int neg = 1;
        // imagine input -= " -042cAb3" we want op -42

        for (int i = 0; i < s.size(); i++) {
            // Step 1 : Skip first ' ' and '0'(first 0 only not next) eg 4024
            if (flag == false &&  (s[i] == ' ' || s[i] == '0')) { // first 0
            skipped when false
                if (s[i] == '0') {
                    flag = true;
                }
                continue;
            }
            // Op = "-42cAb3"  spaces removed

            // Step 2 : Handle signs
            if (flag == false && (s[i] == '-' || s[i] == '+')) {
                if (s[i] == '-') {
                    neg = -1;
                }
                flag = true;
            }
            // op = "-42cAb3" ..sign noted neg=-1 / 1

            // Step 3 : Check if ip is digit or not..break when char
            else if (!isdigit(s[i])) { // or  else if(!(s[i]>='0' &&
            s[i]<='9'))
                break;                 //"42" ..
            }
            // Step 4 : get result
            else {
                flag = true;
                ans *= 10;
                ans += (s[i] - '0') * neg;

                if (ans <    INT_MIN) { // if ans get -213412343242314 we
                return intmin
                    return INT_MIN;
                }
                if (ans > INT_MAX) {
                    return INT_MAX;
                }
            }
        }

        return ans;
    }
};


//recursion

class Solution {
public:

    int rec(string s, int i, int sign, double ans, bool flag) {
        if (ans < INT_MIN) {
            return INT_MIN;
        }
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        if (i == s.size())
            return ans;
            //when false..that state ans not considered for evaluation

        if (flag == false) { // Mark flag true when we encounter a digit
            if (s[i] == ' ') {
                return rec(s, i + 1, sign, ans, false); //just increment..
            }
            if (s[i] == '-') {
                return rec(s, i + 1, -1, ans, true); // increment Set negative sign   and mark
            }
            if (s[i] == '+') {
                return rec(s, i + 1, sign, ans, true); // increment and mark 
            }
            if (s[i] >= '0' && s[i] <= '9') {
                return rec(s, i, sign, ans, true); //break
            } else {
                return ans; 
            }
        }

        if (flag) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0') * sign;
                return rec(s, i + 1, sign, ans, true); 
            } else {
                return ans; 
            }
        }

        return 0;
    }

    int myAtoi(string s) {
        return rec(s, 0, 1, 0, false); // Start with the first character
    }
};

// dont confuse why we pass 1 ..when we are
// handling nondigit elements...just imagine..we
// have passed the white space and sign
// case..thus we are now under digitcheking phase

class Solution {
public:

    int rec(string s, int i, int sign, double ans, bool flag) {
        if (ans < INT_MIN) {
            return INT_MIN;
        }
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        if (i == s.size())
            return ans;
            //when false..that state ans not considered for evaluation

//// Skip non-digit characters and handle sign
        if (flag == false) { // Mark flag true when we encounter a digit
            if (s[i] == ' ') {
                return rec(s, i + 1, sign, ans, false); //just increment.. // Skip whitespace
            }
            if (s[i] == '-') {
                return rec(s, i + 1, -1, ans, true); // increment Set negative sign   and mark
            }
            if (s[i] == '+') {
                return rec(s, i + 1, sign, ans, true); // increment and mark 
            }
            if (s[i] >= '0' && s[i] <= '9') {
                return rec(s, i, sign, ans, true); //break
            } else {
                return ans; 
            }
        }

        if (flag) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0') * sign;
                return rec(s, i + 1, sign, ans, true); 
            } else {
                return ans; 
            }
        }

        return 0;
    }

    int myAtoi(string s) {
        return rec(s, 0, 1, 0, false); // Start with the first character
    }
};
