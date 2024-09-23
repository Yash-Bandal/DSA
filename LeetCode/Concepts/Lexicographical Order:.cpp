/* A lexicographically smaller integer refers to comparing the string representations of integers as if they were words in a dictionary.

Lexicographical Order:
In lexicographical order, numbers are compared character by character, just like words.
The lexicographically smaller integer is the one that would appear first if both numbers were strings and listed in dictionary order.
Example:
Comparing 123 and 321:

As numbers: 123 is smaller than 321.
As strings: 123 is lexicographically smaller than 321 because '1' comes before '3'.
Comparing 1234 and 11234:

As numbers: 1234 is larger than 11234.
As strings: 11234 is lexicographically smaller because '1' comes before '2' in the first position.

Key Point:
A smaller integer in terms of value may not always be lexicographically smaller. For example, 9 is numerically smaller than 123, but lexicographically, 123 is smaller than 9 because '1' comes before '9'. */


440. K-th Smallest in Lexicographical Orderclass Solution {
public:
    int findKthNumber(int n, int k) {
        int currentPrefix = 1; //as 0 is of no use 01 02..all same 
        --k;  // Decrement k to handle zero-based indexing
        
        while (k > 0) {
            int count = countNumbersWithPrefix(currentPrefix, n);
            if (k >= count) {
                currentPrefix++;  // Move to the next prefix
                k -= count;
            } else {
                currentPrefix *= 10;  // Go deeper in the current prefix
                k--;
            }
        }
        
        return currentPrefix;
    }

private:
    int countNumbersWithPrefix(int prefix, int n) {
        long long firstNumber = prefix, nextNumber = prefix + 1;
        int totalCount = 0;

        while (firstNumber <= n) {
            totalCount += static_cast<int>(min(n + 1LL, nextNumber) - firstNumber);
            firstNumber *= 10;
            nextNumber *= 10;
        }

        return totalCount;
    }
};
