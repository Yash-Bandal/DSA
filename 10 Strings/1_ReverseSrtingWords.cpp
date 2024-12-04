//Leet 151
class Solution {
private:
    void reverseWord(string& s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string

        reverse(s.begin(), s.end()); //"eulb si yks eht"..now reverse each
        word

        // Step 2: Use istringstream to extract each word
        istringstream stream(s);
        string ans = "";
        string word;
        // Step 3: Reverse each word and append to the result
        while (stream >> word) {
            reverseWord(word);
            ans += word + " ";
        }
        // we are close "blue is sky the "..just one extra space at
        end..remove
        // it last step

        // Step 4: Remove the trailing space at the end
        if (!ans.empty()) { // silly dont use while 🤫
            ans.pop_back();
        }
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: put inside vector
        vector<string> words;

        istringstream stream(s);
        string word;

        while (stream >> word) {
            words.push_back(word);
        }
        // After fourth word iteration : words = ["the", "sky", "is", "blue"]

        // Step 2 : reverse vector
        reverse(words.begin(), words.end());
        // ["blue", "is", "sky", "the"]

        // Step 3:put inside ans..from vector array to single string
        string ans = "";
        for (auto c : words) {
            ans += c + " ";
        }
        // "blue is sky the "..extra space

        // Step 4 : Remove the extra space
        if (!ans.empty()) { // silly dont use while 🤫
            ans.pop_back();
        }
        return ans;
    }
};
