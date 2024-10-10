//A pair can be used to track index for sums requiring sorted to reduce O(N^2) to O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> vp;
        int ans=0;
        //main goal to reduc O(n sq)
        for(int i=0;i<nums.size();i++){ 
            //push {pair} not (pair)
            vp.push_back({nums[i],i}); //push number and its index to maintain original index track
        }

        //op [(6, 0), (0, 1), (8, 2), (2, 3), (1, 4), (5, 5)]

        //sort
        sort(vp.begin(),vp.end());
        //op [(0, 1), (1, 4), (2, 3), (5, 5), (6, 0), (8, 2)]
       
       //lets consider (0, 1)s 1 as min index
       int minIndex=vp[0].second;
        for(int i=1;i<n;i++){
             ans=max(ans,(vp[i].second-minIndex));
            minIndex=min(minIndex,vp[i].second);

        }
   return ans;

        //traverse and find min path
    }
};
