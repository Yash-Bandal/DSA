//Iterations or on single value.so input is just for imagine
    
class Solution {
public:
    int myAtoi(string s) {
        bool flag = false; // mark flag true when number is digit
        long long ans = 0;
        int neg = 1;
        // imagine input -= " -042cAb3" we want op -42

        for (int i = 0; i < s.size(); i++) {
            // Step 1 : Skip first ' ' and '0'(first 0 only not next) eg 4024
            if (flag == false &&
                (s[i] == ' ' || s[i] == '0')) { // first 0 skipped when false
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
            else if (!isdigit(s[i])) { // or  else if(!(s[i]>='0' && s[i]<='9'))
                break;                 //"42" ..
            }
            // Step 4 : get result
            else {
                flag = true;
                ans *= 10;
                ans += (s[i] - '0') * neg;

                if (ans <
                    INT_MIN) { // if ans get -213412343242314 we return intmin
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
