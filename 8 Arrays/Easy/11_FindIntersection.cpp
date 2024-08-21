
#include <bits/stdc++.h>
using namespace std;
// when returning a vector create a vector function
vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;

    vector<int> visited(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return ans;
}

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
//Union of arr1 and arr2 is 
2 3 4 5 


//2 pointer

#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

vector<int> findIntersection(vector<int>& nums1, vector<int>& nums2) {
    // Sort both arrays
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> intersection;
    int i = 0, j = 0;

    // Use two pointers to find the intersection
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // If both elements are equal, add to the intersection
            intersection.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return intersection;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 2, 3, 5};

    vector<int> intersection = findIntersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : intersection) {
        cout << num << " ";
    }

    return 0;
}    
  
