class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> arr;
        arr.push_back(nums[0] - k);

        for(int i=1;i<nums.size();i++){
            int lb=nums[i]-k;
            int ub=nums[i]+k;

            int nextVal=arr.back()+1;

            if(nextVal <=ub){
                arr.push_back(max(lb,nextVal));
            }
        }
        return arr.size();
    }
};
