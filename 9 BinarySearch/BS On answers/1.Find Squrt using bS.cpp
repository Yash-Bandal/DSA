


#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
      //check if value = n ..n*1ll== avoid long n^21 > numbers ..avoid overflow
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

/*
  int n = 10000000000; // 10^10
 i = 100000  
 If val and i were int, 𝑖^2  for 𝑖 = 100000  would result in overflow since 10^10 > 2^31 − 1 . Using long long prevents this.
  */
OR

#include <bits/stdc++.h>
using namespace std;
//Brute force
int floorSqrt(int n) {
    int ans = 0;

    // Convert n to long long to avoid overflow issues
    long long N = n;  //no need of 1ll

    // Linear search on the answer space:
    for (long long i = 1; i <= N; i++) {
        long long val = i * i;
        if (val <= N) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}
//using inbluilt 
int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}
//BS


int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n = 28; // You can replace with a larger value for testing
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

