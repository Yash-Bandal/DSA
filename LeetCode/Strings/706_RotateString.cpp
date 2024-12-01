class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int cnt = 0;       // Initialize a counter to track the number of shifts

        // Loop to rotate `s` at most `n` times
        while (cnt < n) {
            // Check if `s` matches `goal` after current rotation
            if (s == goal) return true; 

            // Rotate `s` by moving the first character to the end
            char c = s[0];      // Store the first character of `s`
            s.erase(s.begin()); // Remove the first character from `s`
            s.push_back(c);     // Append it to the end of `s`

            cnt++;  // Increment the counter
        }

        // If no match is found after `n` rotations, return false
        return false;
    }
};

/*
// Initial state:
// s = "abcde"
// goal = "cdeab"
// n = 5
// cnt = 0

// First Iteration:
// "abcde" != "cdeab", so continue
// c = 'a'
// s becomes "bcde"
// s becomes "bcdea"
// cnt = 1

// Second Iteration:
// "bcdea" != "cdeab", so continue
// c = 'b'
// s becomes "cdea"
// s becomes "cdeab"
// cnt = 2

// Third Iteration:
// "cdeab" == "cdeab", match found
// Return true and exit

*/


class Solution {
public:
    bool rotateString(string s, string goal) {
        // Step 1: If the lengths are different, `s` can't be rotated to match `goal`
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Step 2: Concatenate `s` with itself to include all rotations of `s`
        string doubled = s + s;
        
        // Step 3: Check if `goal` is a substring of `doubled`
        return doubled.find(goal) != string::npos;
    }
};
