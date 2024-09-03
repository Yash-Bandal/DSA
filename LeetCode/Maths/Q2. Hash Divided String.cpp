class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        string result = "";

        // Iterate over the string in chunks of length k
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            // Calculate the sum of hash values of characters in the current substring
            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }
            // Calculate the hashed character index
            int hashedChar = sum % 26;
            // Convert the hashed character index back to a character
            result += ('a' + hashedChar);
        }

        return result;
    }
};
