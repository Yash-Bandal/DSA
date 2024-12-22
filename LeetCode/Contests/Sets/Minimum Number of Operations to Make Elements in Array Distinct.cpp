class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (true) {
            unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size()) {
                break;
            }
            int c = 0;
            while (c < 3 && !nums.empty()) {
                nums.erase(nums.begin());
                c++;
            }
            cnt++;
        }
        return cnt;
    }
};
