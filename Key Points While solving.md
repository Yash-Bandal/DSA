## Observations

### Pattern Recognition
- Analyze the input-output relationship using basic operations (`+`, `-`, `*`, `/`).
  - Example: **LeetCode 1539** (Kth Missing Positive Number)
    - Input: `arr = [2,3,4,7,11]`, `k = 5` → Output: `9`
    - Observe: Increment `k` based on conditions without requiring a full-fledged algorithm...see..without getting required needed algo  too..you see that
```
when 2<=5 ..5++ k=6  
     3<=6..6++  k=7   
     4<=7 ..7++ k=8 
     7 <=8.......k=9..like this observe pattern in easy and med questions.all
```


### Optimizations

- Sometimes dont use nestded 2 loops to compare 2 arrays vectors
 - maintain a indexVar and increment as per need..and use that indexVar to access array2 element arr2[indVar]
 ```cpp
   //2 loop O(M*N)
   void compareArrays(vector<int> &arr1, vector<int> &arr2) {
    for (int i = 0; i < arr1.size(); i++) {  // Loop through arr1
        for (int j = 0; j < arr2.size(); j++) {  // Loop through arr2
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";  // Common element found
            }
        }
    }

   //1 loop O(M+N)
   void compareArrays(vector<int> &arr1, vector<int> &arr2) {
    int j = 0;  // Index variable for arr2

    for (int i = 0; i < arr1.size(); i++) {  // Loop through arr1
        while (j < arr2.size() && arr2[j] < arr1[i]) {
            j++;  // Move j forward only when arr2[j] is smaller
        }

        if (j < arr2.size() && arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";  // Common element found
        }
    }
```


- In some questions you just need to check back and front s[i+1] i-1...
you may need to iterate over required index only ..like even....eg2914 (e.g., even indices for pair checking).
```cpp
        for (int i = 0; i < s.length(); i += 2) { //chk pairs...
            // If characters in current pair don't match,
            // we need one change to make them equal
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }
```

- If want to operate on string /number that needs to be operatied from back / need to remove characters /int from back
use for(back loop i--)  eg 1903 leeet
```cpp
class Solution {
public:
    string largestOddNumber(string snum) {
        for (int i = snum.length() - 1; i >= 0; i--) {
            if ((snum[i] -'0') % 2 == 1) {
                return snum.substr(0, i + 1);
            }
        }
        return "";
    }
};
```

- Compare 2 map counts or valuse with same keys
```cpp
        for (auto& entry : mppS) {
            if (mppT[entry.first] !=entry.second) { // that is chk cnt of entry in mppT != mppS count
                // it may seem .first .second..but both point to counts ..
                // mppT[entry.first] =mppT count value
                return false;
            }
        }
```


- To check element presence use set 
  - first store the vector elementes to set and use find to check presence
```cpp
unordered_sett<int> uset(vec.begin(),vec.end());

.find(index OR element)
  if (set.find(i) != set.end()) { /* Found */ }
```


- **When more than one numbers in test cases..or when 2 arrays given for operation..try using SETS**


- If a problem requires ranking, shifting, or finding positions, analyze the relation between these 4:
  - `i`, `n`, `%`, and `nums[i]` and then apply operation

### Handling Sum and Array Operations
- For some questions like 1422 2270..Logic is same..that is When **left and right sums** are required, avoid calculating the full sum in each iteration.
  - Compute **total sum** in `O(N)` for loop..i=0 to size()
  - then in 1 loop O(N) ..cacluate leftsum till from i=0 to size()-1..not end size()..as we dont calc for lastest..its auto calc
then rightsum = totalsum - leftsum



- traverse array left to right
```
set l=0;r=n-1
for(i=left -> right)
```

- same for 2d array
```
if r->l
see row and col indices..if row = even...traverse l->r
                       ..if row = odd....traverse r->l
using for loop..
```

- Digit check single double..
```
doublle while(num >= 9){
      //perform until single dig
}
```
  

- Sometimes think from 2 sides...if == not working use !=
  - generally...when value questions..that have input value given and you want to skip them
```
.1 First approach in brain is to check element ..then skip it using continue..wrong
            if (nums[i] == val) {
                i++;
                continue;
            }
.2 First chk in arr if elem != val..tru..then place elems
            if (nums[i] != val) 
            {
                nums[k] = nums[i]; 
                 k++;
            }
```
 - eg leetcode 26..also avoidn changing i in loop

### Edge Cases
- when you may think you are correct and require no changes...and 
sign of no output..that is empty output...see if u have passed through reference "&"

<br>

## Observations
- substring problems are very common ..
- Pass by reference almost all..sometimes u may face err if negelct this
- Always first identify the pattern.. what datatype or algorithm i need to use to get the output
- Use **two-pointer techniques** whenever possible, especially for midpoint-related problems
- **String and array searching**: Use `.find()` , or `string::npos` ON `set`, `map`.
  -  eg :1704 beautifulStringQuestionIsItBoomBaam..


