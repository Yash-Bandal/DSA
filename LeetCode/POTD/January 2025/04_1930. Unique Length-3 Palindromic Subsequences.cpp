class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int> minInd(26, INT_MAX); // store first occurance index
        vector<int> maxInd(26, INT_MIN); // store last occurance index

        // input : a a b c a
        //    i  : 0 1 2 3 4
        //step 1:
        for (int i = 0; i < s.size(); i++) {
            int charInd = s[i] - 'a'; // a:0 , b:1 , c:2 , d:4
            minInd[charInd] = min(minInd[charInd], i);
            maxInd[charInd] = max(maxInd[charInd], i);
        }

        int uniqCnt = 0;

       //step 2:
        for (int charInd = 0; charInd < 26; charInd++) {
            if (minInd[charInd] == INT_MAX || maxInd[charInd] == INT_MIN) {
                continue;
            }
            unordered_set<int> set;
            ////include uniq eles in between only..not the corners
            for (int i = minInd[charInd] + 1; i < maxInd[charInd]; i++) {
                set.insert(s[i]);
            }

            //set updated everytime..just include size in cnt
            /*[]*/
            uniqCnt += set.size();
        }
        return uniqCnt;
    }
};
/*
input : a a s b c a
  i  :  0 1 2 3 4 5

minExist: [∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞,
∞, ∞, ∞]
maxExist: [-∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞,
-∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞]

step1:
minExist: [0, ∞, ∞, 2, 4, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞, ∞]
maxExist: [5, -∞, -∞, 3, 4, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞, -∞]


step2
For 'a' (between indices 0 and 5)
1st  Set: {'a', 's', 'b', 'c'}

For 's' (between indices 2 and 2):
No characters 

For 'b' (between indices 1 and 3): {'a', 's'}
Set: {'a', 's'}

For 'c' (between indices 4 and 4)
No character

Final Count:
Total unique palindromic subsequences = 4 (from 'a') + 2 (from 'b') = 6.


*/
