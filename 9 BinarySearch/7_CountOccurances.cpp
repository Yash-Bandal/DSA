//Brute 

#include<bits/stdc++.h>
using namespace std;
int count(vector<int>& arr, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        // counting the occurrences:
        if (arr[i] == x) cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}

//Geeks
class Solution{
     private:
    //first occ
    int firstOcc(int arr[], int x, int n) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == x) {
                first = mid;
              //eliminate right
                high = mid - 1;
            } else if(arr[mid] < x) {
                low = mid + 1; // look on the right
            }
            else {
                high=mid-1;
            }
        }
        return first;
    }
    //last occ
        int lastOcc(int  arr[], int x, int n) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == x) {
                last = mid;
              //eliminate right
                low = mid + 1;
            } else if(arr[mid] < x) {
                low = mid + 1; // look on the right
            }
            else {
                high=mid-1;
            }
        }
        return last;
    }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int first=firstOcc(arr,x,n);
        if(first == -1){return 0;}
        int last=lastOcc(arr,x,n);
        return (last-first+1);
	    // code here
	}
};
