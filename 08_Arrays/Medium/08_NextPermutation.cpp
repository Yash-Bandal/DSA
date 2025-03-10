
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

--------
    
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {  
        if (A[i] < A[i + 1]) {  
            // index i is the break point
            ind = i;
            break;
        }
    }
    
    // Dry run for break point identification:
    // Given A = {2, 1, 5, 4, 3, 0, 0}
    // Start from the second last index and check:
    // i = 5, A[5] = 0, A[6] = 0 (not A[i] < A[i+1]) → continue
    // i = 4, A[4] = 3, A[5] = 0 (not A[i] < A[i+1]) → continue
    // i = 3, A[3] = 4, A[4] = 3 (not A[i] < A[i+1]) → continue
    // i = 2, A[2] = 5, A[3] = 4 (not A[i] < A[i+1]) → continue
    // i = 1, A[1] = 1, A[2] = 5 → **A[i] < A[i+1] → Break point found at index 1**
    
    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with A[ind]:

    for (int i = n - 1; i > ind; i--) {  
        if (A[i] > A[ind]) {  
            swap(A[i], A[ind]);
            break;
        }
    }
    
    // Finding the next greater element to swap:
    // A[ind] = A[1] = 1
    // Start from last index and find the smallest element greater than 1:
    // i = 6, A[6] = 0 (not > 1) → continue
    // i = 5, A[5] = 0 (not > 1) → continue
    // i = 4, A[4] = 3 (3 > 1) → Swap A[1] and A[4]
    // Updated A = {2, 3, 5, 4, 1, 0, 0}
    
    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());
    
    // Reverse the portion after index 1:
    // A = {2, 3, 0, 0, 1, 4, 5}

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]\n";
    return 0;
}

/*
Final output:
The next permutation is: [2, 3, 0, 0, 1, 4, 5]
*/

