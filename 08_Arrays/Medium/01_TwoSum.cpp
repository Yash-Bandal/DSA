//Brute Force..o n^2

#include <bits/stdc++.h>
using namespace std;
 
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
} 

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


//Optimal Hash/Map
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
Output: This is the answer for variant 2: [1, 3]

//Time Complexity: O(N), where N = size of the array.
//Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).

 //Two pointer- Incorrect..{index not maintained}
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int left=0;
//         int right=nums.size()-1;
        
//         while(left<right){
//             int sum= nums[left] +nums[right];
//             if(sum ==target){
//                 return {left,right};
//             }
//             else if(sum<target){
//                 left++;
//             }
//             else{
//                 right--;
//             }
//         }

 
//         return {-1,-1};
//     }
// };

 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of pairs where each pair contains (value, original index)
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); ++i) {
            indexed_nums.push_back({nums[i], i});
        }

        // Example input:
        // nums = {2, 7, 11, 15}, target = 9
        // indexed_nums before sorting: [(2,0), (7,1), (11,2), (15,3)]

        // Sort based on the values
        sort(indexed_nums.begin(), indexed_nums.end());

        // After sorting (values remain same but ordered):
        // indexed_nums after sorting: [(2,0), (7,1), (11,2), (15,3)]

        int left = 0;
        int right = indexed_nums.size() - 1;

        while (left < right) {
            int sum = indexed_nums[left].first + indexed_nums[right].first;

            // Current sum calculation:
            // (Example for nums = {2,7,11,15} and target = 9)
            // Iteration 1: 2 + 15 = 17  (too high, move right pointer left)
            // Iteration 2: 2 + 11 = 13  (still high, move right pointer left)
            // Iteration 3: 2 + 7 = 9    (match found!)

            if (sum == target) {
                // Return the original indices
                return {indexed_nums[left].second, indexed_nums[right].second};
            } else if (sum < target) {
                left++; // Increase sum by moving left pointer
            } else {
                right--; // Decrease sum by moving right pointer
            }
        }

        // If no solution is found (shouldn't happen in a valid input per problem constraints)
        return {-1, -1};
    }
};

/*The issue with your two-pointer approach in the twoSum function is that you sort the nums array, which 
changes the indices of the elements. As a result, returning {left, right} will not correspond to the original
 indices in the unsorted nums array.*/


#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
