
//2 pointers
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
 int n = nums.size();
    int left = 0, right = n - 1;
    
    // Find the starting position
    while (left <= right && nums[left] != target) {
        left++;
    }

    // Find the ending position
    while (left <= right && nums[right] != target) {
        right--;
    }

    // If the target is not found, return [-1, -1]
    if (left > right) {
        return {-1, -1};
    }

    return {left, right};
    }
};
