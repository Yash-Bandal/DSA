class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (auto sub : words) {
            for (auto main : words) {
                if (main == sub) {
                    continue;
                }
                if(main.find(sub) != -1){
                    ans.push_back(sub);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                string target = words[j];
                string substrChk = words[i];
                // skip when both words same that is
                // when j pointing to i
                if (target == substrChk) {
                    continue;
                }
                // that is when substr is found at any index 0...n
                // and not at any other num (eg -1) its a common substr
                if (target.find(substrChk) != -1) {
                    ans.push_back(substrChk);
                    break;
                }
            }
        }
        return ans;
    }
};
