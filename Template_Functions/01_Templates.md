## Check Prime
```cpp
bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime

    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
              count++;
            }
        }
    }

    return count == 2; 
}
```
 
## Count Digits
```cpp
int countDigits(int n) {
    if (n == 0) return 1; // Edge case: 0 has 1 digit

    int count = 0;
    n = abs(n); // Handle negative numbers

    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}

```

## Find Power
```cpp

const long long MOD = 1e9 + 7; //use if requried ..else not
long long myPow(long long x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x % MOD;

    long long temp = myPow(x, n / 2);
    temp = (temp * temp) % MOD;

    if (n % 2 == 1) {
        return (temp * x) % MOD; // for big numbers..else remove
    } else {
        return temp; // for even powers
    }
}
```

## Palindrome Check
```cpp
bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

```

## HCF and LCM
### GCD (Greatest Common Divisor) using Euclidean Algorithm:
```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```
Or recursively:

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```
### LCM (Least Common Multiple) using GCD:
```cpp
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
```
This version prevents overflow better than (a * b) / gcd(a, b).

----------------------------------------------------


## Advance - Combinetronics
### nCr with Modulo (using factorials)
```cpp
const int MOD = 1e9 + 7;
const int MAX = 1e5;
vector<long long> fact(MAX + 1, 1);

void precomputeFactorials() {
    for (int i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}

long long modInverse(long long a) {
    return myPow(a, MOD - 2); // Fermat's Little Theorem
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD;
}

```
