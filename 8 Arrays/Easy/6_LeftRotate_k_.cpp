#include <bits/stdc++.h>
using namespace std;

// Function to left rotate the array by k positions
void leftRotateArray(vector<int> &nums, int n, int k)
{
    // If k is greater than n, reduce it to within the array size
    k = k % n;

    // Create a temporary array
    int temp[n];

    // Copy elements to the temporary array with the new positions
    for (int i = 0; i < n; i++)
    {
        temp[i] = nums[(i + k) % n];
         //temp[(i + k) % n] = nums[i]; //right rotate
    }

    // Copy elements back to the original array
    for (int i = 0; i < n; i++)
    {
        nums[i] = temp[i];
    }
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int k = 3;

    cout << "Before left Rotate :" << endl;
    printArray(arr, n);

    leftRotateArray(arr, n, k);

    cout << "After left Rotate :" << endl;
    printArray(arr, n);

    return 0;
}

/*
temp = [0, 0, 0, 0, 0, 0, 0]

formula (i + k) % n.

For i = 0: temp[(0 + 3) % 7] = nums[3] = 4
temp = [4, 0, 0, 0, 0, 0, 0]

For i = 1: temp[(1 + 3) % 7] = nums[4] = 5
temp = [4, 5, 0, 0, 0, 0, 0]

For i = 2: temp[(2 + 3) % 7] = nums[5] = 6
temp = [4, 5, 6, 0, 0, 0, 0]

For i = 3: temp[(3 + 3) % 7] = nums[6] = 7
temp = [4, 5, 6, 7, 0, 0, 0]

For i = 4: temp[(4 + 3) % 7] = nums[0] = 1
temp = [4, 5, 6, 7, 1, 0, 0]

For i = 5: temp[(5 + 3) % 7] = nums[1] = 2
temp = [4, 5, 6, 7, 1, 2, 0]

For i = 6: temp[(6 + 3) % 7] = nums[2] = 3
temp = [4, 5, 6, 7, 1, 2, 3]

After this step, temp contains the left-rotated array.
Copy Elements Back to the Original Array:

Now, copy the elements from temp back to nums.

nums[0] = temp[0] = 4
nums[1] = temp[1] = 5
nums[2] = temp[2] = 6
nums[3] = temp[3] = 7
nums[4] = temp[4] = 1
nums[5] = temp[5] = 2
nums[6] = temp[6] = 3

Final Output
nums = [4, 5, 6, 7, 1, 2, 3]

*/

//Brute
class Solution
{
public:
    void leftRotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        // If k is greater than n, reduce it to within the array size
        k = k % n;

        // Create a temporary vector to store the first k elements
        vector<int> temp(k);

        // Copy the first k elements to the temporary vector
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[i];
        }

        // Shift the remaining elements to the left by k positions
        for (int i = 0; i < n - k; i++)
        {
            nums[i] = nums[i + k];
        }

        // Copy the elements from the temporary vector to the end of the array
        for (int i = 0; i < k; i++)
        {
            nums[n - k + i] = temp[i];
        }
    }
};

//..ask for visualization and dry run GPT 

