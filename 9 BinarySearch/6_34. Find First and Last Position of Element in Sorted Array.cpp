//Note O(log n) is good < than O(N) , than O(N2)
//2 pointers  O(N)
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


//Linear search  Linear search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                //first updates only once
                if(first==-1){
                    first=i;
                }
                last=i;//last all time upd
            }
           
        }
         return {first,last};
    }
};
