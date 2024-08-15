class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum=0;
        for(int i=0;i<=nums.size();i++)  //run = to n not < use <=
        {
            sum=sum+i;
        }
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            sum2=sum2+nums[i];
        }
        int missingNum=sum-sum2;
        return missingNum;
        
    }
}; 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int expectedSun=0;
        for(int i=0;i<=nums.size();i++)  //run = to n not < use <=
        {
            expectedSun=expectedSun+i;
        }
        int resSum=0;
        for(int i=0;i<nums.size();i++){
            resSum=resSum+nums[i];
        }
        int missingNum=expectedSun-resSum;
        return missingNum;
        
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
            int n = nums.size(); // Length of the array, which is n

    // Create a boolean vector to keep track of which numbers are present
    vector<bool> present(n + 1, false);
    
    // Mark the numbers present in the array
    for (int num : nums) {
        if (num >= 0 && num <= n) {
            present[num] = true;
        }
    }
    
    // Find the first number that is not marked as present
    for (int i = 0; i <= n; ++i) {
        if (!present[i]) {
            return i;
        }
    }
    
    // In case no number is missing, return -1 or handle as needed
    return -1;
   
        
    }
};
