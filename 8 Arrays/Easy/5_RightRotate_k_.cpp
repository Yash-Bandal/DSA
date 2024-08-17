
// Right rotate by k
#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in an array
void rotateArray(vector<int> &nums, int n, int k)
{
    // If k is greater than n, reduce it to within the array size
    k = k % n;

    // Create a temporary array
    int temp[n];

    // Copy elements to the temporary array with the new positions
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
        //  temp[i] = nums[(i + k) % n];  //left rotate
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

    cout << "Before right Rotate :" << endl;
    printArray(arr, n);

    rotateArray(arr, n, k);

    cout << "After right Rotate :" << endl;
    printArray(arr, n);

    return 0;
}

/*
temp = [0, 0, 0, 0, 0, 0, 0]

formula (i + k) % n.

For i = 0: temp[(0 + 3) % 7] = temp[3] = nums[0] = 1
temp = [0, 0, 0, 1, 0, 0, 0]

For i = 1: temp[(1 + 3) % 7] = temp[4] = nums[1] = 2
temp = [0, 0, 0, 1, 2, 0, 0]

For i = 2: temp[(2 + 3) % 7] = temp[5] = nums[2] = 3
temp = [0, 0, 0, 1, 2, 3, 0]

For i = 3: temp[(3 + 3) % 7] = temp[6] = nums[3] = 4
temp = [0, 0, 0, 1, 2, 3, 4]

For i = 4: temp[(4 + 3) % 7] = temp[0] = nums[4] = 5
temp = [5, 0, 0, 1, 2, 3, 4]

For i = 5: temp[(5 + 3) % 7] = temp[1] = nums[5] = 6
temp = [5, 6, 0, 1, 2, 3, 4]

For i = 6: temp[(6 + 3) % 7] = temp[2] = nums[6] = 7
temp = [5, 6, 7, 1, 2, 3, 4]

After this step, temp contains the right-rotated array.
Copy Elements Back to the Original Array:

Now, copy the elements from temp back to nums.

nums[0] = temp[0] = 5
nums[1] = temp[1] = 6
nums[2] = temp[2] = 7
nums[3] = temp[3] = 1
nums[4] = temp[4] = 2
nums[5] = temp[5] = 3
nums[6] = temp[6] = 4

Final Output
nums = [5, 6, 7, 1, 2, 3, 4]

*/
