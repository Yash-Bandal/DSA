class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (size_t i{0}; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

/*
     [1 4 3 2] => [1 2 3 4]
thus [1 2 3 4]=> [(1 , 2) , (3,4)]..logically first num is small of the pair
1+3 = 4 =ans
*/
