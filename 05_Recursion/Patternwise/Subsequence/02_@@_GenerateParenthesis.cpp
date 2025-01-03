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
