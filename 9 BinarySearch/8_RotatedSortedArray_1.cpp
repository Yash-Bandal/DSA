
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // consider Left portion is Sorted
            if (nums[low] <= nums[mid]) {  //equalto condition very imp
                // consider always first if target is in middle
                // Traverse only sorted portion
                if (nums[low] <= target && target <= nums[mid]) { //low -target-mid
                    // eliminate un nneeded right
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }
            // Else right is sorted definately
            else {
                if (nums[mid] <= target && target <= nums[high]) { //mid-target-high
                    // eliminate un nneeded left  
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};


/////////////////
//Brute linear search
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}

//Optimal binary


#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}


