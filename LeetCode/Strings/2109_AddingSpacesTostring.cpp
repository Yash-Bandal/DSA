// class Solution {  //gives TLE
// public:
//     string addSpaces(string s, vector<int>& spaces) {
//         string str = "";
//         int cnt = 0;
//         for (auto c : s) {

//             for (int i = 0; i < spaces.size(); i++) {
//                 if (cnt == spaces[i]) {
//                     str += " ";
//                 }
//             }
//             cnt++;
//             str += c;
//         }
//         return str;
//     }
// };

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int i = 0;
        int spcInd = 0;
        for (auto c : s) {

            if (spcInd < spaces.size() && i == spaces[spcInd]) {
                str += " ";
                spcInd++;
            }
            i++;
            str += c;
        }
        return str;
    }
};

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string res = "";
        int ind = 0;
        for (int i = 0; i < n; i++) {

            if (ind < spaces.size() && i == spaces[ind]) {
                res += " ";
                ind++;
            }
            res += s[i];
        }
        return res;
    }
};
