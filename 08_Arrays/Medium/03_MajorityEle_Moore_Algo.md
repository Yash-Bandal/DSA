## Problem Statement : 
Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

### Brute Force
```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
```

### Better - Map


```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

```

### Optimal Moores Algorithm
## Boyer-Moore Voting Algorithm

### Step 1: Find a Candidate Majority Element
1. **Initialize Variables**:
   - Set `cnt = 0` (vote count).
   - Set `el = 0` (potential majority element).
2. **Traverse the Array**:
   - If `cnt == 0`, assign `el = nums[i]` and set `cnt = 1`.
   - If `nums[i] == el`, increase `cnt`.
   - Otherwise, decrease `cnt`.
3. **Result of Step 1**:
   - At the end of this loop, `el` **might** be the majority element.

### Step 2: Validate the Candidate
1. **Check if the Problem Guarantees a Majority Element**:
   - If the problem (e.g., LeetCode **169. Majority Element**) guarantees a majority element, the candidate is correct.
2. **Otherwise, Verify the Candidate**:
   - Traverse the array again and count occurrences of `el`.
   - If `el` appears more than `n/2` times, it is the majority element.
   - Otherwise, return an indication (e.g., `-1`) that no majority element exists.





```cpp

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
```
### Complexity Analysis
- **Time Complexity**: **O(n)** (single pass to find candidate + single pass to validate).
- **Space Complexity**: **O(1)** (only a few integer variables are used).
