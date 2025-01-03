//1422. Maximum Score After Splitting a String
//My tey
class Solution {
public:
    int maxScore(string s) {
        int sum = 0;
        int maxSum = INT_MIN;
        int c0 = 0;
        int c1 = 0;
        int k, j;

        for (int i = 0; i < s.size() - 1; i++) {
            // always reset at start of loop not end of loop
            c0 = 0;
            c1 = 0;

            for (k = 0; k <= i; k++) {
                if (s[k] == '0') {
                    c0++;
                }
            }

            for (j = i + 1; j < s.size(); j++) {
                if (s[j] == '1') {
                    c1++;
                }
            }
            sum = c0 + c1;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

// optimizeed
class Solution {
public:
    int maxScore(string s) {
        int sum = 0;
        int maxSum = INT_MIN;
        int c0 = 0;
        int c1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                c1++;
            }
        }

        for (int i = 0; i < s.size() - 1; i++) {  //calculate till n-1 only..dont forget logic..
            if (s[i] == '0') {
                c0++;
            } else if (s[i] == '1') {
                c1--;
            }

            sum = c0 + c1;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

// run till size-1..as we check only 1s cnt for right
// part..and no zero..this .size()-1 is to handle string
// with size 2
// we have totalcount of 1s c1..thus we not need to check for last
// ele as if its 0..we dont care ..if its 1..we dont perform
// 'c1--'..thus count of 1 retained

/*
Logic of optimied..count 1s first and then in one iteration..track both counts 
*/


//2270 2270. Number of Ways to Split Array
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long totalSum = 0;  //if u use int..runtime error
        long long leftSum = 0;
        long long rightSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum = totalSum - leftSum;
            if(leftSum >= rightSum){
                count++;
            }
        }
        return count;
    }
};
