


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
