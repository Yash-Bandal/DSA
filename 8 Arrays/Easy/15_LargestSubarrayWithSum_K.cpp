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
                len = max(len, j - i + 1);  //here j-1+1 first is 3-1+1 that is 3..next 4-3+1 ie 2
        }                                       //thus retur max(3,2)=3
    }
    return len;
}

int main()
{                  //0  1  2  3  4  
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

/*
Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space
*/
//iterations reduce 5 4 3 2 1 visualize easy



/*
Dry Run of the Code:

Input:
    a = {2, 3, 5, 1, 9}
    k = 10

Initial Setup:
    n = 5
    len = 0

Outer Loop (i from 0 to 4):
--------------------------------
1. i = 0:
    - j = 0:
        - Subarray = {2}
        - s = 2
        - (s != k, len remains 0)
    - j = 1:
        - Subarray = {2, 3}
        - s = 2 + 3 = 5
        - (s != k, len remains 0)
    - j = 2:
        - Subarray = {2, 3, 5}
        - s = 2 + 3 + 5 = 10
        - (s == k, len = max(0, 3) = 3)
    - j = 3:
        - Subarray = {2, 3, 5, 1}
        - s = 2 + 3 + 5 + 1 = 11
        - (s != k, len remains 3)
    - j = 4:
        - Subarray = {2, 3, 5, 1, 9}
        - s = 2 + 3 + 5 + 1 + 9 = 20
        - (s != k, len remains 3)
        
2. i = 1:
    - j = 1:
        - Subarray = {3}
        - s = 3
        - (s != k, len remains 3)
    - j = 2:
        - Subarray = {3, 5}
        - s = 3 + 5 = 8
        - (s != k, len remains 3)
    - j = 3:
        - Subarray = {3, 5, 1}
        - s = 3 + 5 + 1 = 9
        - (s != k, len remains 3)
    - j = 4:
        - Subarray = {3, 5, 1, 9}
        - s = 3 + 5 + 1 + 9 = 18
        - (s != k, len remains 3)
        
3. i = 2:
    - j = 2:
        - Subarray = {5}
        - s = 5
        - (s != k, len remains 3)
    - j = 3:
        - Subarray = {5, 1}
        - s = 5 + 1 = 6
        - (s != k, len remains 3)
    - j = 4:
        - Subarray = {5, 1, 9}
        - s = 5 + 1 + 9 = 15
        - (s != k, len remains 3)
        
4. i = 3:
    - j = 3:
        - Subarray = {1}
        - s = 1
        - (s != k, len remains 3)
    - j = 4:
        - Subarray = {1, 9}
        - s = 1 + 9 = 10
        - (s == k, len = max(3, 2) = 3)
        
5. i = 4:
    - j = 4:
        - Subarray = {9}
        - s = 9
        - (s != k, len remains 3)

Final Result:
    The length of the longest subarray with sum = 10 is: 3
    The subarray is: {2, 3, 5}
*/
---------------------------------------------------------------------------------------


//Optimizing the Naive Approach (Using two loops): 
/*
Intuition: If we carefully observe, we can notice that to get the sum of the current 
 subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

This is how we can remove the third loop and while moving the j pointer, we can calculate the sum.
*/
    


#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

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

/*  O(N^2)
Dry Run of the getLongestSubarray function:

Input:
- Array: {2, 3, 5, 1, 9}
- Target Sum (k): 10

Steps:

1. Initialization:
   - n = 5 (size of the array)
   - len = 0 (to store the maximum length of subarray)

2. Outer Loop: i = 0 (starting index)

   a. Inner Loop: j = 0
      - s = 0 + 2 = 2
      - s != k, len remains 0

   b. Inner Loop: j = 1
      - s = 2 + 3 = 5
      - s != k, len remains 0

   c. Inner Loop: j = 2
      - s = 5 + 5 = 10
      - s == k, len = max(0, 2 - 0 + 1) = 3

   d. Inner Loop: j = 3
      - s = 10 + 1 = 11
      - s != k, len remains 3

   e. Inner Loop: j = 4
      - s = 11 + 9 = 20
      - s != k, len remains 3

3. Outer Loop: i = 1 (starting index)

   a. Inner Loop: j = 1
      - s = 0 + 3 = 3
      - s != k, len remains 3

   b. Inner Loop: j = 2
      - s = 3 + 5 = 8
      - s != k, len remains 3

   c. Inner Loop: j = 3
      - s = 8 + 1 = 9
      - s != k, len remains 3

   d. Inner Loop: j = 4
      - s = 9 + 9 = 18
      - s != k, len remains 3

4. Outer Loop: i = 2 (starting index)

   a. Inner Loop: j = 2
      - s = 0 + 5 = 5
      - s != k, len remains 3

   b. Inner Loop: j = 3
      - s = 5 + 1 = 6
      - s != k, len remains 3

   c. Inner Loop: j = 4
      - s = 6 + 9 = 15
      - s != k, len remains 3

5. Outer Loop: i = 3 (starting index)

   a. Inner Loop: j = 3
      - s = 0 + 1 = 1
      - s != k, len remains 3

   b. Inner Loop: j = 4
      - s = 1 + 9 = 10
      - s == k, len = max(3, 4 - 3 + 1) = 3

6. Outer Loop: i = 4 (starting index)

   a. Inner Loop: j = 4
      - s = 0 + 9 = 9
      - s != k, len remains 3

Final Output:
- The length of the longest subarray with sum k = 10 is 3.
*/




//HashMap O(N)



// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         for (int j = i; j < n; j++) { // ending index
//             // add all the elements of
//             // subarray = a[i...j]:
//             long long s = 0;
//             for (int K = i; K <= j; K++) {
//                 s += a[K];
//             }

//             if (s == k)
//                 len = max(len, j - i + 1);  //here j-1+1 first is 3-1+1 that is 3..next 4-3+1 ie 2
//         }                                       //thus retur max(3,2)=3
//     }
//     return len;
// }

// int main()
// {                  //0  1  2  3  4  
//     vector<int> a = {2, 3, 5, 1, 9};
//     long long k = 10;
//     int len = getLongestSubarray(a, k);
//     cout << "The length of the longest subarray is: " << len << "\n";
//     return 0;
// }







// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         for (int j = i; j < n; j++) { // ending index
//             // add all the elements of
//             // subarray = a[i...j]:
//             long long s = 0;
//             for (int K = i; K <= j; K++) {
//                 s += a[K];
//             }

//             if (s == k)
//                 len = max(len, j - i + 1);  //here j-1+1 first is 3-1+1 that is 3..next 4-3+1 ie 2
//         }                                       //thus retur max(3,2)=3
//     }
//     return len;
// }

// int main()
// {                  //0  1  2  3  4  
//     vector<int> a = {2, 3, 5, 1, 9};
//     long long k = 10;
//     int len = getLongestSubarray(a, k);
//     cout << "The length of the longest subarray is: " << len << "\n";
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); 

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);  //i+1 is the x length //+1 index...
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;  //reverse enginnering k=sum-rem

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    //             //0  1  2  3  4 
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}






/*
### Dry Run and Basic Explanation

Let's dry-run the optimized code step by step for finding the longest subarray with a given sum `k`. The provided array is `{2, 3, 5, 1, 9}`, and the target sum `k` is `10`.

### Initial Setup:
- **Array `a`:** `[2, 3, 5, 1, 9]`
- **Target Sum `k`:** `10`
- **Prefix Sum Map (`preSumMap`):** `{}` (Initially empty)
- **Current Sum (`sum`):** `0` (Initialized to 0)
- **Maximum Length (`maxLen`):** `0` (Initialized to 0)

### Iteration 1:
- **Index `i = 0`:** 
    - Current element: `2`
    - `sum += a[0]` → `sum = 2`
    - Check if `sum == k` → `2 != 10`, so `maxLen` remains `0`.
    - Calculate `rem = sum - k` → `rem = 2 - 10 = -8`
    - `-8` is not in `preSumMap`, so nothing changes.
    - Add `sum` to `preSumMap` → `preSumMap = {2: 0}` (Key `2`, Value `0` (index))

### Iteration 2:
- **Index `i = 1`:** 
    - Current element: `3`
    - `sum += a[1]` → `sum = 5`
    - Check if `sum == k` → `5 != 10`, so `maxLen` remains `0`.
    - Calculate `rem = sum - k` → `rem = 5 - 10 = -5`
    - `-5` is not in `preSumMap`, so nothing changes.
    - Add `sum` to `preSumMap` → `preSumMap = {2: 0, 5: 1}`

### Iteration 3:
- **Index `i = 2`:** 
    - Current element: `5`
    - `sum += a[2]` → `sum = 10`
    - Check if `sum == k` → `10 == 10`, so `maxLen = max(0, 3) = 3`
    - Calculate `rem = sum - k` → `rem = 10 - 10 = 0`
    - `0` is not in `preSumMap`, so nothing changes.
    - Add `sum` to `preSumMap` → `preSumMap = {2: 0, 5: 1, 10: 2}`

### Iteration 4:
- **Index `i = 3`:**
    - Current element: `1`
    - `sum += a[3]` → `sum = 11`
    - Check if `sum == k` → `11 != 10`, so `maxLen` remains `3`.
    - Calculate `rem = sum - k` → `rem = 11 - 10 = 1`
    - `1` is not in `preSumMap`, so nothing changes.
    - Add `sum` to `preSumMap` → `preSumMap = {2: 0, 5: 1, 10: 2, 11: 3}`

### Iteration 5:
- **Index `i = 4`:**
    - Current element: `9`
    - `sum += a[4]` → `sum = 20`
    - Check if `sum == k` → `20 != 10`, so `maxLen` remains `3`.
    - Calculate `rem = sum - k` → `rem = 20 - 10 = 10`
    - `10` is in `preSumMap` with index `2`.
    - Calculate length of subarray from `preSumMap[10] + 1` to `i`:
        - `len = 4 - 2 = 2`
        - `maxLen = max(3, 2) = 3`
    - Add `sum` to `preSumMap` → `preSumMap = {2: 0, 5: 1, 10: 2, 11: 3, 20: 4}`

### Final Output:
- The length of the longest subarray with sum `10` is `3`. The subarray `[2, 3, 5]` has this sum.

### Key Concepts:
1. **Prefix Sum:** Accumulating the sum of elements from the start up to the current index.
2. **Hash Map (`preSumMap`):** Stores the first occurrence of each prefix sum, enabling quick lookups to determine the length of subarrays that match the target sum `k`.
3. **Optimal Subarray Length:** Calculated by checking if the difference `sum - k` exists in the map, indicating that the subarray between these indices sums to `k`.

This method reduces the time complexity to `O(n)` because it involves a single pass through the array and quick lookups in the map.

*/
Eazy Two Pointers



#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

check dry run on gpt
/*
### Dry Run of the Two Pointer Approach:

#### Input:
- Array: `a = [2, 3, 5, 1, 9]`
- Target sum `k = 10`

### Initial Setup:
- `left = 0`, `right = 0`
- `sum = a[0] = 2`
- `maxLen = 0`

### Step-by-Step Execution:

1. **Initial State:**
   - Array: `[2, 3, 5, 1, 9]`
   - Pointers: `left = 0`, `right = 0`
   - `sum = 2`, `maxLen = 0`

2. **Iteration 1 (`right = 0`):**
   - `sum = 2` (less than `k`)
   - Move `right` to `1`
   - Add `a[1]`: `sum = 2 + 3 = 5`
   - **State:**
     - Array: `[2, 3, 5, 1, 9]`
     - Pointers: `left = 0`, `right = 1`
     - `sum = 5`, `maxLen = 0`

3. **Iteration 2 (`right = 1`):**
   - `sum = 5` (less than `k`)
   - Move `right` to `2`
   - Add `a[2]`: `sum = 5 + 5 = 10`
   - `sum = k`, update `maxLen`: `maxLen = 3`
   - **State:**
     - Array: `[2, 3, 5, 1, 9]`
     - Pointers: `left = 0`, `right = 2`
     - `sum = 10`, `maxLen = 3`

4. **Iteration 3 (`right = 2`):**
   - `sum = 10` (equal to `k`)
   - Move `right` to `3`
   - Add `a[3]`: `sum = 10 + 1 = 11`
   - `sum > k`, reduce from left:
     - Subtract `a[0]`: `sum = 11 - 2 = 9`, then `left = 1`
     - `sum < k`
   - **State:**
     - Array: `[2, 3, 5, 1, 9]`
     - Pointers: `left = 1`, `right = 3`
     - `sum = 9`, `maxLen = 3`

5. **Iteration 4 (`right = 3`):**
   - `sum = 9` (less than `k`)
   - Move `right` to `4`
   - Add `a[4]`: `sum = 9 + 9 = 18`
   - `sum > k`, reduce from left:
     - Subtract `a[1]`: `sum = 18 - 3 = 15`, then `left = 2`
     - Subtract `a[2]`: `sum = 15 - 5 = 10`, then `left = 3`
     - `sum = k`, update `maxLen`: `maxLen = 3`
   - **State:**
     - Array: `[2, 3, 5, 1, 9]`
     - Pointers: `left = 3`, `right = 4`
     - `sum = 10`, `maxLen = 3`

6. **Iteration 5 (`right = 4`):**
   - `sum = 10` (equal to `k`)
   - `right` moves out of bounds, loop ends.

### Final Output:
- The length of the longest subarray with sum `k = 10` is `3`.

### Visual Representation of Pointer Movement:


*/
    ///////////////////////////////////////////////////////////
//Print subarray

#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> getLongestSubarrayWithSum(vector<int>& a, long long k) {
    int n = a.size(); // size of the array

    int left = 0, right = 0; // two pointers
    long long sum = a[0];
    int maxLen = 0;
    int start = 0, end = 0; // to store the indices of the subarray

    while (right < n) {
        // If sum > k, reduce the subarray from left until sum becomes less or equal to k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // If sum == k, update maxLen and store the indices
        if (sum == k) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
                end = right;
            }
        }

        // Move the right pointer forward
        right++;
        if (right < n) sum += a[right];
    }

    // Prepare the subarray
    vector<int> subarray;
    if (maxLen > 0) {
        subarray.insert(subarray.end(), a.begin() + start, a.begin() + end + 1);
    }

    return {maxLen, subarray};
}

int main() {
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;

    // Get the length and subarray with the sum k
    auto result = getLongestSubarrayWithSum(a, k);
    int len = result.first;
    vector<int> subarray = result.second;

    // Output the result
    cout << "The length of the longest subarray is: " << len << "\n";
    if (len > 0) {
        cout << "The subarray is: ";
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << "\n";
    } else {
        cout << "No subarray found with the sum " << k << "\n";
    }

    return 0;
}
