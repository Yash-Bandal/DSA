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
