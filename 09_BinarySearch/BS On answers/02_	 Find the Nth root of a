


#include <bits/stdc++.h>
using namespace std;

// Power exponential method:
//You can use the linear method or recursive but it has high complexity as compared to this lonarithmic N
//This is Logarithmic optimal
long long power(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2  == 1) {    //odd simply decrement
            exp--;  
            ans = ans * base;
        }
        else {  //if even
            exp /= 2;     //if power is even..half it and square the base  //Eg 2^10 == 4^5
            base = base * base;
        }
    }
    return ans;
}
//Recursive
long long power(int base, int expo) {
    if (expo == 0) return 1; // Base case: any number raised to 0 is 1
    return base * power(base, expo - 1); // Multiply base recursively
}

//Iterative
long long power(int base, int expo) {
    long long result = 1; // Initialize result
    for (int i = 0; i < expo; i++) {
        result *= base; // Multiply the base expo times
    }
    return result;
}

int NthRoot(int n, int m) {
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = power(i, n);
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
//BS




#include <bits/stdc++.h>
using namespace std;

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:

//we use this 0 1 2 to avoid overflow conditon eg n=10 m=10^9...thus mid = 10^5 and 10^5 *10^5 *10^5 is very big non storable

// we also pass ressult m so that we can compare  at run time each step
int func(int mid, int n, int m) {//we modify the function..and use linear power function to simplify understanding...
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;  //simple linear power func
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;  //when 2 received
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


