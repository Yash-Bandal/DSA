class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (romanMap[s[i]] < romanMap[s[i + 1]]) {
                ans -= romanMap[s[i]];
            } else {
                ans += romanMap[s[i]];
            }
        }
        return ans;
    }
};

/*
The subtraction condition is for cases like "IV", "XL", etc., 
where a smaller numeral precedes a larger numeral, forming a subtractive combination.

Example: "IV" (4)

1. First Iteration (i = 0):
   - Current character: s[i] = 'I' → m[s[i]] = 1
   - Next character: s[i+1] = 'V' → m[s[i+1]] = 5
   - Since m[s[i]] < m[s[i+1]] (1 < 5), the subtraction condition is executed:
       ans -= m[s[i]];
       ans = 0 - 1 = -1

2. Second Iteration (i = 1):
   - Current character: s[i] = 'V' → m[s[i]] = 5
   - Next character: s[i+1] (out of bounds), so the condition m[s[i]] < m[s[i+1]] fails.
   - The else condition is executed:
       ans += m[s[i]];
       ans = -1 + 5 = 4

Final result: ans = 4 (correctly calculated for "IV").
*/

