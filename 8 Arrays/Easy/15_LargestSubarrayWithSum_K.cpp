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

//TC =O(N^3)//not applicable for big input





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
