
//see Recursion and backtracking..DSA Book 1
//TC O(2^n) recursion..thus limited 10 testcases

class Solution {
private:
    void generate(vector<int>& nums, vector<vector<int>>& res, vector<int>& one, int i) {
        if (i == nums.size()) { // or >=
            res.push_back(one);
            return;
        }
        // Include nums[i]
        one.push_back(nums[i]);
        generate(nums, res, one, i + 1);     //recursion
        // Exclude nums[i]
        one.pop_back();                    //backtrack
        generate(nums, res, one, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one;
        int startInd = 0;
        generate(nums, res, one, startInd);
        return res;
    }
};

// pass by reference if u see empty [] vector in result
// see what we are returning..here 2d array that stores 1d array
/*
first we reach []
thus res = { [1 2 3] } first..

first we complete recursion...then go for backtrack when first 'one' [1 2 3] pushed

Dry Run for input nums = [1, 2, 3]:

1. Initial call: subsets([1, 2, 3])
    - res = []
    - one = []
    - start recursion with i = 0

2. First recursive call: generate([1, 2, 3], res, one, 0)
    - one = [] (empty)
    - Include nums[0] = 1
    - one = [1]
    - Recurse with i = 1
    
3. Second recursive call: generate([1, 2, 3], res, one, 1)
    - one = [1]
    - Include nums[1] = 2
    - one = [1, 2]
    - Recurse with i = 2
    
4. Third recursive call: generate([1, 2, 3], res, one, 2)
    - one = [1, 2]
    - Include nums[2] = 3
    - one = [1, 2, 3]
    - Recurse with i = 3
    
5. Fourth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [1, 2, 3] to res
    - res = [[1, 2, 3]]
    - Backtrack: pop 3 from one
    - one = [1, 2]
    - Recurse with i = 3

6. Fifth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [1, 2] to res
    - res = [[1, 2, 3], [1, 2]]
    - Return to previous call

7. Backtrack to i = 1: pop 2 from one
    - one = [1]
    - Recurse with i = 2

8. Sixth recursive call: generate([1, 2, 3], res, one, 2)
    - one = [1]
    - Include nums[2] = 3
    - one = [1, 3]
    - Recurse with i = 3

9. Seventh recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [1, 3] to res
    - res = [[1, 2, 3], [1, 2], [1, 3]]
    - Backtrack: pop 3 from one
    - one = [1]
    - Recurse with i = 3

10. Eighth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [1] to res
    - res = [[1, 2, 3], [1, 2], [1, 3], [1]]
    - Backtrack: pop 1 from one
    - one = []
    - Recurse with i = 1

11. Ninth recursive call: generate([1, 2, 3], res, one, 1)
    - one = []
    - Include nums[1] = 2
    - one = [2]
    - Recurse with i = 2

12. Tenth recursive call: generate([1, 2, 3], res, one, 2)
    - one = [2]
    - Include nums[2] = 3
    - one = [2, 3]
    - Recurse with i = 3

13. Eleventh recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [2, 3] to res
    - res = [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3]]
    - Backtrack: pop 3 from one
    - one = [2]
    - Recurse with i = 3

14. Twelfth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [2] to res
    - res = [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2]]
    - Backtrack: pop 2 from one
    - one = []
    - Recurse with i = 2

15. Thirteenth recursive call: generate([1, 2, 3], res, one, 2)
    - one = []
    - Include nums[2] = 3
    - one = [3]
    - Recurse with i = 3

16. Fourteenth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [3] to res
    - res = [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3]]
    - Backtrack: pop 3 from one
    - one = []
    - Recurse with i = 3

17. Fifteenth recursive call: generate([1, 2, 3], res, one, 3)
    - Base case: i == nums.size(), add one = [] to res
    - res = [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []]
    - Return to previous call

18. End of recursion: Return final res = [[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []]

*/


//TC O(2*n  * n )   BOOK DSA 2
//Power set Bit Manip
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int num = 0; num < pow(2, n); num++) {
            vector<int> one;
            for (int i = 0; i < n; i++) {
                // if index marked 1 in table..include that index element
                if ((num & (1 << i)) != 0) {
                    one.push_back(nums[i]);
                }
            }
            res.push_back(one);
        }
        return res;
    }
};

/*
silly 
 if ((nums[i] & (1 << i)) == 1)..dont check for 1 and dont check for nums[i]

 check for num..columns...0 -> 7
 use != 0 
*/

/*
Example Dry Run with Input: nums = {1, 2, 3}
Initial setup:

nums = {1, 2, 3}
n = 3 (size of nums)
res = [] (result list)
Loop through all possible subsets (from 0 to 2^3 - 1 = 7):

For num = 0 (binary 000):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 0 & 1 = 0 → no element added.
    Check bit 1: num & (1 << 1) = 0 & 2 = 0 → no element added.
    Check bit 2: num & (1 << 2) = 0 & 4 = 0 → no element added.
    Current subset: []
    Add [] to res: res = [[]]

For num = 1 (binary 001):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 1 & 1 = 1 → include 1.
    Check bit 1: num & (1 << 1) = 1 & 2 = 0 → no element added.
    Check bit 2: num & (1 << 2) = 1 & 4 = 0 → no element added.
    Current subset: [1]
    Add [1] to res: res = [[], [1]]

For num = 2 (binary 010):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 2 & 1 = 0 → no element added.
    Check bit 1: num & (1 << 1) = 2 & 2 = 2 → include 2.
    Check bit 2: num & (1 << 2) = 2 & 4 = 0 → no element added.
    Current subset: [2]
    Add [2] to res: res = [[], [1], [2]]

For num = 3 (binary 011):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 3 & 1 = 1 → include 1.
    Check bit 1: num & (1 << 1) = 3 & 2 = 2 → include 2.
    Check bit 2: num & (1 << 2) = 3 & 4 = 0 → no element added.
    Current subset: [1, 2]
    Add [1, 2] to res: res = [[], [1], [2], [1, 2]]

For num = 4 (binary 100):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 4 & 1 = 0 → no element added.
    Check bit 1: num & (1 << 1) = 4 & 2 = 0 → no element added.
    Check bit 2: num & (1 << 2) = 4 & 4 = 4 → include 3.
    Current subset: [3]
    Add [3] to res: res = [[], [1], [2], [1, 2], [3]]

For num = 5 (binary 101):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 5 & 1 = 1 → include 1.
    Check bit 1: num & (1 << 1) = 5 & 2 = 0 → no element added.
    Check bit 2: num & (1 << 2) = 5 & 4 = 4 → include 3.
    Current subset: [1, 3]
    Add [1, 3] to res: res = [[], [1], [2], [1, 2], [3], [1, 3]]

For num = 6 (binary 110):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 6 & 1 = 0 → no element added.
    Check bit 1: num & (1 << 1) = 6 & 2 = 2 → include 2.
    Check bit 2: num & (1 << 2) = 6 & 4 = 4 → include 3.
    Current subset: [2, 3]
    Add [2, 3] to res: res = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3]]

For num = 7 (binary 111):
    one = [] (empty subset)
    Check bit 0: num & (1 << 0) = 7 & 1 = 1 → include 1.
    Check bit 1: num & (1 << 1) = 7 & 2 = 2 → include 2.
    Check bit 2: num & (1 << 2) = 7 & 4 = 4 → include 3.
    Current subset: [1, 2, 3]
    Add [1, 2, 3] to res: res = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]

After completing the loop, the final result list `res` contains all subsets of `{1, 2, 3}`:
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
*/
