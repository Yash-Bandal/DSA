
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


//Brute 
class Solution
{
public:
 
//Place this function in above template ..just dont forget to pass size n
void rightRotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        // If k is greater than n, reduce it to within the array size
        k = k % n;

        // Create a temporary vector to store the last k elements
        vector<int> temp(k);

        // Copy the last k elements to the temporary vector
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[n - k + i];
        }

        // Shift the remaining elements to the right by k positions
        for (int i = n - 1; i >= k; i--)
        {
            nums[i] = nums[i - k];
        }

        // Copy the elements from the temporary vector to the beginning of the array
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

//Optimal solution that doesnt use temp array so no xtra space

//Using Reversealgo
/*
Approach 2: Using ” Reversal Algorithm “

Approach:

For Rotating Elements to right
Step 1: Reverse the last k elements of the array

Step 2: Reverse the first n-k elements of the array.

Step 3: Reverse the whole array.

For Eg , arr[]={1,2,3,4,5,6,7} , k=2
*/

#include <iostream>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
// Function to Rotate k elements to right
void Rotateeletoright(int arr[], int n, int k)
{
  // Reverse first n-k elements
  Reverse(arr, 0, n - k - 1);
  // Reverse last k elements
  Reverse(arr, n - k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  Rotateeletoright(arr, n, k);
  cout << "After Rotating the k elements to right ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
/*
Initial Array:
arr = [1, 2, 3, 4, 5, 6, 7]
n = 7
k = 2

Step 1: Reverse the first n-k elements
Before Reverse:
[1, 2, 3, 4, 5, 6, 7]

After Reverse (Reverse first 5 elements):
[5, 4, 3, 2, 1, 6, 7]

Step 2: Reverse the last k elements
We reverse the elements from index n-k to n-1 which is 5 to 6.
Before Reverse:
[5, 4, 3, 2, 1, 6, 7]

After Reverse (Reverse last 2 elements):
[5, 4, 3, 2, 1, 7, 6]

Step 3: Reverse the whole array
Now, we reverse the entire array from index 0 to n-1 which is 0 to 6.
Before Reverse:
[5, 4, 3, 2, 1, 7, 6]

After Reverse:
[6, 7, 1, 2, 3, 4, 5]

Final Output:
arr = [6, 7, 1, 2, 3, 4, 5]
*/
