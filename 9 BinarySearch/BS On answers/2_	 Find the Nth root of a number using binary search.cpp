


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

