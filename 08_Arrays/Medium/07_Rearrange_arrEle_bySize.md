## Problem Statement:
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

### Brute Force

```cpp  
#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n) {
    
    // Define 2 vectors, one for storing positive 
    // and another for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) 
            pos.push_back(A[i]); // Store positive elements
        else 
            neg.push_back(A[i]); // Store negative elements
    }

    // Positives on even indices, negatives on odd.
    for (int i = 0; i < n / 2; i++) {
        A[2 * i] = pos[i];    // Assign positive number at even index
        A[2 * i + 1] = neg[i]; // Assign negative number at odd index
    }

    return A;
}

int main() {
    // Array Initialization
    int n = 4;
    vector<int> A {1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A, n);

    // Expected Output: 1 -4 2 -5
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
```


### Optimal equal +ve and -ve
```cpp
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  
  vector<int> A = {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

```




### Optimal 1 pass ..unequal +ve and -ve
```cpp
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 8;
  vector<int> A {1,-1 ,-2, 3 ,4 ,-5, 6, 8}; 

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

```

### walkthrough

### **Input:**
```cpp
vector<int> A {1, -1, -2, 3, 4, -5, 6, 8};
int n = 8;
```

### **Step 1: Segregate Positive and Negative Numbers**
We create two separate vectors:
```
Positive numbers: [1, 3, 4, 6, 8]
Negative numbers: [-1, -2, -5]
```

### **Step 2: Compare the Sizes**
```
pos.size() = 5
neg.size() = 3
```
Since `pos.size() > neg.size()`, we follow the logic where positives are greater than negatives.

### **Step 3: Fill the Array Alternately**
We place elements alternatively until all negative numbers are placed:

| Index | Step                         | Result Array       |
|--------|------------------------------|----------------------|
| 0      | `A[0] = pos[0] = 1`           | `[1, _, _, _, _, _, _, _]`  |
| 1      | `A[1] = neg[0] = -1`          | `[1, -1, _, _, _, _, _, _]` |
| 2      | `A[2] = pos[1] = 3`           | `[1, -1, 3, _, _, _, _, _]`  |
| 3      | `A[3] = neg[1] = -2`          | `[1, -1, 3, -2, _, _, _, _]` |
| 4      | `A[4] = pos[2] = 4`           | `[1, -1, 3, -2, 4, _, _, _]` |
| 5      | `A[5] = neg[2] = -5`          | `[1, -1, 3, -2, 4, -5, _, _]` |

### **Step 4: Fill Remaining Positive Numbers**
Since `pos.size() > neg.size()`, we place the remaining positive numbers at the end:

| Index | Step                          | Result Array       |
|--------|------------------------------|----------------------|
| 6      | `A[6] = pos[3] = 6`           | `[1, -1, 3, -2, 4, -5, 6, _]` |
| 7      | `A[7] = pos[4] = 8`           | `[1, -1, 3, -2, 4, -5, 6, 8]` |

### **Final Output:**
```
1 -1 3 -2 4 -5 6 8
```

### **Time Complexity:**
- **O(N)**: We iterate over the array multiple times (once to segregate, once to place values).


---

## Dry Run of Rearrange by Sign Algorithm

### Input:
n = 8
A = {1, -1, -2, 3, 4, -5, 6, 8}

### Initial Setup:
We initialize two vectors: `pos` and `neg` to store the positive and negative values separately.

### Loop to Segregate Positives and Negatives:
| Index (i) | A[i]  | Action               | pos         | neg        |
|-----------|-------|----------------------|-------------|------------|
| 0         | 1     | Positive -> pos      | {1}         | {}         |
| 1         | -1    | Negative -> neg      | {1}         | {-1}       |
| 2         | -2    | Negative -> neg      | {1}         | {-1, -2}   |
| 3         | 3     | Positive -> pos      | {1, 3}      | {-1, -2}   |
| 4         | 4     | Positive -> pos      | {1, 3, 4}   | {-1, -2}   |
| 5         | -5    | Negative -> neg      | {1, 3, 4}   | {-1, -2, -5} |
| 6         | 6     | Positive -> pos      | {1, 3, 4, 6} | {-1, -2, -5} |
| 7         | 8     | Positive -> pos      | {1, 3, 4, 6, 8} | {-1, -2, -5} |

### Check Condition for Pos and Neg Sizes:
- `pos.size() = 5`, `neg.size() = 3`
- Since `pos.size() > neg.size()`, we proceed to the **else block**.

### Fill the Array Alternately:
We fill elements from `pos` and `neg` until we run out of negatives.

| Step | Index (i) | A[i]  | pos Index | neg Index | Array State |
|------|----------|-------|-----------|-----------|-------------|
| 1    | 0       | 1     | 0         | -         | {1, _, _, _, _, _, _, _} |
| 2    | 1       | -1    | -         | 0         | {1, -1, _, _, _, _, _, _} |
| 3    | 2       | 3     | 1         | -         | {1, -1, 3, _, _, _, _, _} |
| 4    | 3       | -2    | -         | 1         | {1, -1, 3, -2, _, _, _, _} |
| 5    | 4       | 4     | 2         | -         | {1, -1, 3, -2, 4, _, _, _} |
| 6    | 5       | -5    | -         | 2         | {1, -1, 3, -2, 4, -5, _, _} |

### Fill Remaining Positives:
Since negatives are exhausted, place remaining positives at the end.

| Step | Index | A[i]  | pos Index | Array State |
|------|--------|-------|-----------|-------------|
| 1    | 6      | 6     | 3         | {1, -1, 3, -2, 4, -5, 6, _} |
| 2    | 7      | 8     | 4         | {1, -1, 3, -2, 4, -5, 6, 8} |

### Final Output:
The rearranged array is:
```
1 -1 3 -2 4 -5 6 8
```

### Another Example:
#### Input:
```cpp
vector<int> A {1, -1, -2, 3, 4, -5, 6, 8};
```
#### Output:
```
1 -1 3 -2 4 -5 6 8
```

---
