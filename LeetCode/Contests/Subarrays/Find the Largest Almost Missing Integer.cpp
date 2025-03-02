//Learn to use subarray traversal
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        // subarray of size k traveresed like this
        for (int i = 0; i <= n - k; i++) { //<=
            unordered_set<int> seen;
            // mark subarray elems as seen
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (auto it : seen) {
                mpp[it]++;
            }
        }
        int res = -1;
        for (auto it : mpp) {
            if (it.second == 1) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};
