class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt = 0;
        unordered_map<char,int>mpp;
        for(auto it : s ){
            mpp[it]++;
        }
        for(auto it : mpp){
            // if(it.second == 1){
                
            if(it.second %2 == 1){  //we check odd frequencies ..not count 1
                cnt++;
            }
        }
        if(cnt <= k  && k <= s.length()){
            return true;
        }
        return false;
        
    }
};

/*
Question : You need to decide:
Can you split the characters of s into exactly k palindrome strings?

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble",
                            "anbna" + "elle", 
                            "anellena" + "b"
 exactly k=2 pals

 A palindrome can have at most one character with an odd count (this character goes in the middle of the palindrome).
 eg 
 aba
 abba  here freq even
 abbba  odd freq 3
 thus check ..if odd freq count a ccc bbbbb ddddddd...< k 
*/
