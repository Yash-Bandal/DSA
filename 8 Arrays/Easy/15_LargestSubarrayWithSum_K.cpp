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

/*
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

