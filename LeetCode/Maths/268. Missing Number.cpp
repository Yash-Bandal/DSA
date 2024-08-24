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
        
        for(int i=0;i<=nums.size();i++){
            int flag=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==i)
                    flag=1;
            }
            if(flag==0)
                return i;
            
        }
        return -1;
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


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        
        // Use a vector to dynamically allocate memory
        vector<int> hash(N + 1, 0);

        // Populate the hash array
        for (int i = 0; i < N; i++)
            hash[nums[i]]++;

        // Find the missing number
        for (int i = 0; i <= N; i++) {  // Use i <= N because the missing number could be 0 as well
            if (hash[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int N=nums.size();
    int xor1 = 0, xor2 = 0;

//itwrate through array and later for xor1 which need xtra included missing num..xor1 ^with N..the last num
    for (int i = 0; i < N ; i++) {
        xor2 = xor2 ^ nums[i]; // XOR of array elements
        xor1 = xor1 ^ i ; //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
    }
};


