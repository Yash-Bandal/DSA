
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //if all same initially
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
           low++;
                high--;
                continue;
            }
            // consider Left portion is Sorted
            if (nums[low] <= nums[mid]) {  //equalto condition very imp
                // consider always first if target is in middle
                // Traverse only sorted portion
                if (nums[low] <= target && target <= nums[mid]) { //low -target-mid
                    // eliminate un nneeded right
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }
            // Else right is sorted definately
            else {
                if (nums[mid] <= target && target <= nums[high]) { //mid-target-high
                    // eliminate un nneeded left  
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

