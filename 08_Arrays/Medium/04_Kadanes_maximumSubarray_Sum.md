## 53. Maximum Subarray
### 1 Brute O( n cube)

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
```

### 2 Better O (n sq)
```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

```

### 3 Optimal Kadane O(N)

# Kadane's Algorithm - Maximum Subarray Sum

## Algorithm
Kadane's Algorithm is an efficient method to find the **maximum sum contiguous subarray** in a given array of integers. The algorithm runs in **O(N) time complexity** and uses a simple iterative approach.

### **Steps to Implement Kadane's Algorithm:**
1. **Initialize Variables:**
   - Set `maxi = LONG_MIN` (stores the maximum subarray sum found so far).
   - Set `sum = 0` (tracks the current subarray sum).

2. **Iterate through the Array:**
   - Add the current element to `sum`.
   - If `sum` is greater than `maxi`, update `maxi = sum`.
   - If `sum` becomes negative, reset it to `0` (discard negative contributions).

3. **Return `maxi` as the maximum subarray sum.**





```cpp
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // Stores the maximum subarray sum found so far
    long long sum = 0;         // Stores the current subarray sum

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Add current element to sum

        if (sum > maxi) {
            maxi = sum; // Update maximum sum if the current sum is greater
        }

        // If the current sum becomes negative, reset it to 0
        if (sum < 0) {
            sum = 0;
        }
    }

    // If we want to consider an empty subarray (optional check)
    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
        // Step-by-step visualization:
        // Iteration | arr[i] | sum (so far) | maxi
        // --------------------------------------
        //     1    |   -2   |  0  (reset)  | -2
        //     2    |    1   |  1           |  1
        //     3    |   -3   |  0  (reset)  |  1
        //     4    |    4   |  4           |  4
        //     5    |   -1   |  3           |  4
        //     6    |    2   |  5           |  5
        //     7    |    1   |  6           |  6
        //     8    |   -5   |  1           |  6
        //     9    |    4   |  5           |  6

```

## **Example Walkthrough**
### **Input:**
```cpp
arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }
```

### **Step-by-step Execution:**
| Iteration | `arr[i]` | `sum` (so far) | `maxi` (max so far) |
|-----------|----------|----------------|----------------------|
| 1         | -2       | 0 (reset)       | -2                   |
| 2         | 1        | 1               | 1                    |
| 3         | -3       | 0 (reset)       | 1                    |
| 4         | 4        | 4               | 4                    |
| 5         | -1       | 3               | 4                    |
| 6         | 2        | 5               | 5                    |
| 7         | 1        | 6               | 6                    |
| 8         | -5       | 1               | 6                    |
| 9         | 4        | 5               | 6                    |

### **Output:**
```cpp
The maximum subarray sum is: 6
```

## **Complexity Analysis**
- **Time Complexity:** `O(N)` (since we traverse the array only once)
- **Space Complexity:** `O(1)` (constant extra space)

## **Edge Cases Considered**
1. **All elements are negative** → The algorithm still returns the largest single element.
2. **Array with all positive elements** → The sum of the entire array is returned.
3. **Single element array** → The single element itself is the maximum subarray sum.



---
TO PRINT THE SUB ARRAY WE NEED TO KNOW INDEX STRT AND END

There might be more than one subarray with the maximum sum. We need to print any of them.

Intuition: Our approach is to store the starting index and the ending index of the subarray. Thus we can easily get the subarray afterward without actually storing the subarray elements.

If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

So, we will keep a track of the starting index inside the loop using a start variable.
We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.
The rest of the approach will be the same as Kadane’s Algorithm.

---
```cpp
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }  //instrad of max inbuilt use this func

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
```
