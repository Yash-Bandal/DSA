//Brute
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            
            // Check all elements to the right of arr[i]
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    isLeader = false;  //dont forget this else TLE error
                    break; // No need to check further if a larger element is found
                }
            }
            
            // If arr[i] is a leader, add it to the result
            if (isLeader) {
                res.push_back(arr[i]);
            }
        }
        
        return res;
    }
};



------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    bool leader = true;

    // Checking whether arr[i] is greater than all 
    // the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
      ans.push_back(arr[i]);

  }

  return ans;
}

int main() {

  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeadersBruteForce(arr, n);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  cout << endl;
  return 0;
}

/*
### Dry Run of the Code:

#### Given Input:
   arr = {10, 22, 12, 3, 0, 6}, n = 6

#### Iterations:

1. **i = 0**, arr[i] = 10
   - Compare with right elements: {22, 12, 3, 0, 6}
   - 22 > 10 → Not a leader (break)

2. **i = 1**, arr[i] = 22
   - Compare with right elements: {12, 3, 0, 6}
   - 22 > all → **Leader** → ans = {22}

3. **i = 2**, arr[i] = 12
   - Compare with right elements: {3, 0, 6}
   - 12 > all → **Leader** → ans = {22, 12}

4. **i = 3**, arr[i] = 3
   - Compare with right elements: {0, 6}
   - 6 > 3 → Not a leader (break)

5. **i = 4**, arr[i] = 0
   - Compare with right elements: {6}
   - 6 > 0 → Not a leader (break)

6. **i = 5**, arr[i] = 6
   - No right elements → **Leader** → ans = {22, 12, 6}

#### Final Output:
   **Leaders in the array:** `22 12 6`

*/



----------------------------------------------------------------------------------
    //Optimal
    


#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);
  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }
  return ans;
}

int main() {
 
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}


---------------------------------------------------------------------------------
    What is the output of the following C++ code?

#include <iostream>
using namespace std;

int main() {
    char * a = "Hello\0World";
    cout << strlen(a) << endl;
    return 0;
}
Options: Pick one correct answer from below

11

5

6

Error
    The function strlen() calculates the length of the string up to the first null character (\0).
    
