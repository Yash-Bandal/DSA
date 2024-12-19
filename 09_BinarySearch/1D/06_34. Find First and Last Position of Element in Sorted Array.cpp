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


//LB UB 2( * O)Log N
class Solution {
private:
    int lowerBound(vector<int>& arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    int upperBound(vector<int>& arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target, n);
        int ubInd = upperBound(nums, target, n);
        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb, ubInd - 1};
    }
};

//Pure BS
//O(Log n)


//Pure O(Log n) BS
class Solution {
    private:
    //first occ
    int firstOcc(vector<int>& arr, int x, int n) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == x) {
                first = mid;
              //eliminate right
                high = mid - 1;
            } else if(arr[mid] < x) {
                low = mid + 1; // look on the right
            }
            else {
                high=mid-1;
            }
        }
        return first;
    }
    //last occ
        int lastOcc(vector<int>& arr, int x, int n) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == x) {
                last = mid;
              //eliminate right
                low = mid + 1;
            } else if(arr[mid] < x) {
                low = mid + 1; // look on the right
            }
            else {
                high=mid-1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n=nums.size();
        int first=firstOcc(nums,target,n);
        if(first == -1){return {-1,-1};}
        int last=lastOcc(nums,target,n);
        return {first,last};
    }
};
