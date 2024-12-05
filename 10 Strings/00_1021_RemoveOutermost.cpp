class Solution {
public:
    string removeOuterParentheses(string s) {
        int opened = 0;
        string res = "";
        for (auto c : s) {
            if (c == '(') {
                if (opened > 0) {  //first false..outermost skipped as opened=0
                    res += c;     
                }
                opened++;       //second opened=1
            } else if (c == ')') {   //this skipped third
                opened--;
                if (opened > 0) {
                    res += c;
                }
            }
        }
        return res;
    }
};




/*
"(()())(())(()(()))"

Index   Character   Action                 opened   Result (res)
0       (           Skip (outermost)        1       ""
1       (           Add to res              2       "("
2       )           Add to res              1       "()"
3       (           Add to res              2       "()("
4       )           Add to res              1       "()()"
5       )           Skip (outermost)        0       "()()"
6       (           Skip (outermost)        1       "()()"
7       (           Add to res              2       "()()("
8       )           Add to res              1       "()()()"
9       )           Skip (outermost)        0       "()()()"
10      (           Skip (outermost)        1       "()()()"
11      (           Add to res              2       "()()()( "
12      )           Add to res              1       "()()()()"
13      (           Add to res              2       "()()()()("
14      (           Add to res              3       "()()()()(("
15      )           Add to res              2       "()()()()((("
16      )           Add to res              1       "()()()()(()"
17      )           Skip (outermost)        0       "()()()()()"

"()()()()(())"
*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};
