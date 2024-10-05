//Same as Lower bound..return lower bound 

//stl
//Binary Search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int n=nums.size();
         int ans=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
         

       return ans;
        
    }
};


//Binary Search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int n=nums.size();
         int ans=n;
         int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid] >= target){
              ans=mid;
                high=mid-1;
            }else{
                    low=mid+1;
            }
      
        }
       return ans;
        
    }
};


//Linear Search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int n=nums.size();
         int ans=n;
        for(int i=0;i<n;i++){
            if(nums[i] >= target){
                ans=i;
                return i;
            }
        }
       return ans;
        
    }
};


