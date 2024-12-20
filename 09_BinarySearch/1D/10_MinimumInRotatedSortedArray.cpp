class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Optimization extra
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]); // iw already sorted remaining half
                break;
            }

            // check left sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]); // left most of sorted is always
                low = mid + 1;             // minimul ie arr[low] here }
            }
            // Right is else sorted
            else {
                ans = min(ans, nums[mid]); // ..mid to high
                high = mid - 1;
            }
        }

        return ans;
    }
};
