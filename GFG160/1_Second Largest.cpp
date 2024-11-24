class Solution {
public:
    // Function to return the second largest element 
    int getSecondLargest(vector<int> &arr) { 
        // Initialize variables for the largest and second largest
        int largest = -1, secondLargest = -1;  
          
        // Iterate over the array
        for (int num : arr) { 
            // Update the largest and second largest 
            if (num > largest) {
                secondLargest = largest; // Update second largest to the previous largest
                largest = num;           // Update largest to current number
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;     // Update second largest
            }
        } 
        
        // If secondLargest hasn't been updated, return -1 (no valid second largest)
        return secondLargest;
    }
};
