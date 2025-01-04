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
