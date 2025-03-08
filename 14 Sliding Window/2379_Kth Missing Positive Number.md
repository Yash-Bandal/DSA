### 2379. Minimum Recolors to Get K Consecutive Black Blocks
### Problem Statement :
Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
---
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
---

### My Logic On Sq
```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cw = 0;
        int n = blocks.size();
        int minCw = n;
      
        for (int i = 0; i <= (n - k); i++) {
            cw = 0;
            //No need to count consecutive B as we reset cw to 0 at strt of loop
            for (int j = i; j < (i + k); j++) {
                if (blocks[j] == 'W') {
                    cw++;
                }
            }
            minCw = min(cw, minCw);
        }
        return minCw;
    }
};
```

### Optimized sliding window
```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cw = 0;  // Count of 'W' in the current window
        int n = blocks.size();
        
        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') cw++;
        }
        
        int minCw = cw;  // Store the minimum 'W' count
        
        // Sliding window approach
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') cw++;      // Add new character to the window
            if (blocks[i - k] == 'W') cw--;  // Remove old character from the window
            
            minCw = min(minCw, cw);
        }
        
        return minCw;
    }
};
```
