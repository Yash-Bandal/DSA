class Solution {
private:
    void generate(vector<string> &res, string str, int open, int close) {
        // base case
        if (open == 0 && close == 0) {
            res.push_back(str);
            return;
        }
        if (open > 0) {
            generate(res, str + "(", open - 1, close + 1);
        }
        if (close > 0) {
            generate(res, str + ")", open, close - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, 0);
        return res;
    }
};


/*
generate("", 3, 0)   // Start with empty string
├── generate("(", 2, 1)         // Add '('
│   ├── generate("((", 1, 2)    // Add '('
│   │   ├── generate("(((", 0, 3)   // Add '('
│   │   │   ├── generate("((()", 0, 2)   // Add ')'
│   │   │   │   ├── generate("((())", 0, 1)   // Add ')'
│   │   │   │   │   ├── generate("((()))", 0, 0)   // Add ')', valid combination
│   │   │   │   │   └── Backtrack
│   │   │   │   └── Backtrack
│   │   │   └── Backtrack
│   │   ├── generate("(()", 1, 1)    // Add ')'
│   │   │   ├── generate("(()(", 0, 2)   // Add '('
│   │   │   │   ├── generate("(()()", 0, 1)   // Add ')'
│   │   │   │   │   ├── generate("(()())", 0, 0)   // Add ')', valid combination
│   │   │   │   │   └── Backtrack
│   │   │   │   └── Backtrack
│   │   │   └── Backtrack
│   │   └── Backtrack
│   ├── generate("()", 2, 0)    // Add ')'
│   │   ├── generate("()(", 1, 1)    // Add '('
│   │   │   ├── generate("()((", 0, 2)   // Add '('
│   │   │   │   ├── generate("()(()", 0, 1)   // Add ')'
│   │   │   │   │   ├── generate("()(())", 0, 0)   // Add ')', valid combination
│   │   │   │   │   └── Backtrack
│   │   │   │   └── Backtrack
│   │   │   └── Backtrack
│   │   ├── generate("()()", 1, 0)    // Add ')'
│   │   │   ├── generate("()()(", 0, 1)   // Add '('
│   │   │   │   ├── generate("()()()", 0, 0)   // Add ')', valid combination
│   │   │   │   └── Backtrack
│   │   │   └── Backtrack
│   │   └── Backtrack
│   └── Backtrack
└── Backtrack

*?

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void generate(vector<string>& res, string str, int open, int close) {
        // Base case: If no more open or close parentheses to add
        if (open == 0 && close == 0) {
            res.push_back(str);
            return;
        }

        // Add open parentheses if available
        if (open > 0) {
            generate(res, str + "(", open - 1, close);
        }

        // Add close parentheses if there are more open parentheses added than close ones
        if (close > open) {
            generate(res, str + ")", open, close - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, n); // Start with n open and n close parentheses to add
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n; // Input the value of n (number of pairs of parentheses)

    vector<string> result = sol.generateParenthesis(n);
    
    cout << "Valid Parenthesis combinations for n = " << n << " are:" << endl;
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}

// 
// Enter the value of n: 3
// Valid Parenthesis combinations for n = 3 are:
// ((()))
// (()())
// (())()
// ()(())
// ()()()
// 
