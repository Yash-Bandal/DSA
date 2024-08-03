#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);

    for (size_t i{0}; i < n; i++)
    {
        // Skip this element if already processed
        if (visited[i] == true)
        {
            continue;
        }
        // count
        int count{1};

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j] && visited[i] == false)
            {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " :" << count << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}

/*
Time Complexity: O(N*N)
Space Complexity:  O(N)


Visualization:
Initialization:
arr[] = {10, 5, 10, 15, 10, 5}
n = 6
visited = {false, false, false, false, false, false}

First iteration (i = 0):
arr[0] = 10
visited[0] = false
Initialize count = 1
Compare arr[0] with subsequent elements:
arr[1] != arr[0] (no match)
arr[2] == arr[0] (match), set visited[2] = true, increment count = 2
arr[3] != arr[0] (no match)
arr[4] == arr[0] (match), set visited[4] = true, increment count = 3
arr[5] != arr[0] (no match)
Print 10 3
visited = {false, false, true, false, true, false}

Second iteration (i = 1):
arr[1] = 5
visited[1] = false
Initialize count = 1
Compare arr[1] with subsequent elements:
arr[2] != arr[1] (no match)
arr[3] != arr[1] (no match)
arr[4] != arr[1] (no match)
arr[5] == arr[1] (match), set visited[5] = true, increment count = 2
Print 5 2
visited = {false, false, true, false, true, true}

Third iteration (i = 2):
arr[2] = 10
visited[2] = true (skip)

Fourth iteration (i = 3):
arr[3] = 15
visited[3] = false
Initialize count = 1
Compare arr[3] with subsequent elements:
arr[4] != arr[3] (no match)
arr[5] != arr[3] (no match)
Print 15 1
visited = {false, false, true, false, true, true}

Fifth iteration (i = 4):
arr[4] = 10
visited[4] = true (skip)

Sixth iteration (i = 5):
arr[5] = 5
visited[5] = true (skip)
*/
