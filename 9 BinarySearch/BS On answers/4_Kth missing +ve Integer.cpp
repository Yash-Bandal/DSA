class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};

// using maxHeap
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        int ind = 0; // maintain index from 0 to req
        int ans = 1; // the range of num in array is 1 to max(num in array)

        while (pq.size() != k) {
            if (ind < n && ans < arr[ind] || ind >= n) {
                pq.push(ans);
            }
            if (ind < n && ans == arr[ind]) {
                ind++;
            }
            ans++; // after checking both only we judge answer
        }

        return pq.top();
    }
};
/*
for [2,3,4,7,11]

we start from ans =1
 -- till <2 we add missing 1 in heap missing  [1]
 -- till 3 nothing missing 
 -- till 4 nothing missing now
 -- till 7 ..we need to add 5 6      [6 5 1]
 -- till 11..we need to add 8 9 10 ..but [10 9 8 6 5 1] now allowd as size of heap exceding as acc to while condition
 thus stop at 9 [9 8 6 5 1]

 return top 9
*/

//bs



#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

