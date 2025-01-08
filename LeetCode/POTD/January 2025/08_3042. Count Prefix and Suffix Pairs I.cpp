class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string preSuf = words[i];
                string target = words[j];
                if ( target.find(preSuf) == 0 // prefix check ..start index = 0
                    && target.rfind(preSuf) == (target.size() - preSuf.size() )) //suffix check..start index of sufix
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*
Note :
in vector string with both for loops..range for and index for
entire word is accessed with operator..whether it be index i or iterator it

here :
preSuf is the word just behind the target .
our aim is to chk if target's prefix and sufix is 'presuf'
ie 'ababa' has 'aba' as both sufix and prefix


we use rfind to find from end
and     find to find from start of vector element



here...
in first if check..we see that target.find(presuf) returns 0
thus 0 == 0 prefix start index


then  in second if check..we see that target.rfind(presuf) returns index position of sufix
eg heree 5 - 3 = 2
thus 2 == 2 sufux start index
eg  :

preSuf         target
a b a    in  a b a b a
             0 1 2 3 4
    
    we see here 'a b a' is  suffix in target that starts at index pos 2

thus increment cnt ..


in yesterdtay question we used target.find( substr) != -1
that is after -1..... 0 1 2 3 4...any number we get as substr index we return ans


*/
