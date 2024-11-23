class Solution {
public:
    // Helper function to reverse a portion of the array
    void reverseArray(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Handle the case where d > n

        // Step 1: Reverse the entire array
        reverseArray(arr, 0, n - 1);
        
        // Step 2: Reverse the first n - d elements
        reverseArray(arr, 0, n - d - 1);
        
        // Step 3: Reverse the last d elements
        reverseArray(arr, n - d, n - 1);
    }
};
