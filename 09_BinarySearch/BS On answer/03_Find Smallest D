// class Solution {  //TLE
// private:
//     int maxEle(vector<int>& nums) {
//         int maxI = INT_MIN;
//         for (int i = 0; i < nums.size(); i++) {
//             maxI = max(maxI, nums[i]);
//         }
//         return maxI;
//     }

// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int maxI = maxEle(nums);

//         for (int i = 1; i <= maxI; i++) {
//             int sum = 0;
//             for (int j = 0; j < nums.size(); j++) {

//                 sum += ceil((double)(nums[j]) / (double)(i));
//             }
//             if (sum <= threshold) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
private:
    int maxEle(vector<int>& nums) {
        int maxI = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxI = max(maxI, nums[i]);
        }
        return maxI;
    }
    int sumByD(vector<int>& arr, int div) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxI = maxEle(nums);

        int low = 1;
        int high = maxI;

        while (low <= high) {
            int sum = 0;
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
