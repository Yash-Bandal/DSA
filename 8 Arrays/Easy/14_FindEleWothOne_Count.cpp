//Brute Force  eazy logic
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;  //reset to 0

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }


    //if the array contains no single element.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
  //  vector<int> arr = {4, 4 , 1, 2, 1, 2}; //try this to get -1
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

/*
Time Complexity: O(N2), where N = size of the given array.
Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).

Space Complexity: O(1) as we are not using any extra space.
*/

