//Leetcode contest 419
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        // ruun from i=0 to 2..3 subarray iters
        for (int i = 0; i < n - k + 1; i++) { // 3 subarrays n-k+1= 8-6+1=3
            // place map inside loop as we need it everry time for diff
            // subarray

            // step 1 : store in map
            unordered_map<int, int> mpp;
            for (int j = i; j < i + k; j++) {
                mpp[nums[j]]++;
            }

            // step 2 : store in freq map in desc
            //  need a descending ordered sorted map storing pair as key and its
            //  sum as value
            //  map   pair{1,2}key: value  ...sorting acc to pair
            map<pair<int, int>, int, greater<pair<int, int>>> sortedFreq;
            // storing in
            for (const auto& entry : mpp) {
                sortedFreq[{entry.second, entry.first}] +=
                    entry.second * entry.first;
            }
            // step 3 : calculate sum of top 2 values of sorted freq ..
            int count = 0;
            int sum = 0;
            for (const auto& it : sortedFreq) {
                if (count >= x) { // 1 check
                    break;
                }
                sum += it.second; // 2.calculate sum
                count++;          // 3. increment
            }  // step4
            res.push_back(sum);
        }
        return res;
    }
};

/*
3 subarrays so run iuter loop for 3 times only
the number 3 is obtained every time for different array by n-k+1


  At this point, we have the current subarray
        Subarray from index `i` to `i + k - 1`
        For example,
        if i = 0 and k = 6:
        First subarray: [1, 1, 2, 2, 3, 4]

        If i = 1:
        Second subarray: [1, 2, 2, 3, 4, 2]

        If i = 2:
        Third subarray: [2, 2, 3, 4, 2, 3]


        Start
         First subarray: [1, 1, 2, 2, 3, 4]
        //step 1 : map store acc to freqs
         mpp={
            (1:2),
            (2:2),
            (3:1),
            (4:1)
         }
         
         //step 2:
         sorted freq Map will have pair and its value
            sortedFreq={
            {1:2} : 2       //2*1
            {2:2} : 4,      //2*2
            {3:1} : 3,      //3*1
            {4:1} : 4       //4*1
         }


        //step 3:
         count=0;
         sum=0;
         calculate sum
        1. for  it =  {1:2} : 2
          sum+=it.second =0+2=2
          count=1

        2. for  it =  {2:2} : 4
          sum+=it.second =2+2=4
          count=2

        3 for  it =  {2:2} : 4
        prev   count=2...break no sum calc




     //step 4:
     res.append 6

     ...same for next 2


     ...
     final  [6, 10, 12]



*/
