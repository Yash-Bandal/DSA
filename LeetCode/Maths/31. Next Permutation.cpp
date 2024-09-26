class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());

    }
};
-------------------------------------------------------------------------
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind;

        // Find the first index from the end where nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) { 
                ind = i;
                break;
            }
        }
        //edge case
        
        // If no such index exists, the array is in descending order, reverse to get smallest permutation
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Swap with the first greater element from the end
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverse the right part of the array after the index `ind`
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
