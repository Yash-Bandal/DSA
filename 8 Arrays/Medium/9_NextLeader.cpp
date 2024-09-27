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
