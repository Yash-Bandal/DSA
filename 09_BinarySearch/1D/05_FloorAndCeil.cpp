#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int>& a, int n, int x) {
    int floor = -1, ceil = -1;
    int low = 0, high = n - 1;
    
    // Find floor of x
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {       //<=
            floor = a[mid];  // This could be the floor, but there might be a larger one  //retrun value anot index
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Reset the low and high for finding ceil
    low = 0, high = n - 1;

    // Find ceil of x
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x) { //>= lower bound
            ceil = a[mid];  // This could be the ceiling, but there might be a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return {floor, ceil};
}

int main() {
    int n = 6, x = 5;
    vector<int> a = {3, 4, 7, 8, 8, 10};
    pair<int, int> result = getFloorAndCeil(a, n, x);
    cout << result.first << " " << result.second << endl;
    return 0;
}
