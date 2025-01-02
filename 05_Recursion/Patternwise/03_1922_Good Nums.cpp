class Solution {
public:
    // 5 = 0,2,4,6,8..single digit even nums..that fit at even indice
    // 4 = 2,3,5,7..single digit primes..that fit and odd indice
    const int MOD = 1e9 + 7;
    long long myPow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x; // not  return 'n' ..silly mistake
        }
        long long temp = myPow(x, n / 2);

        if (n % 2 == 1) {                   // odd
            return (temp * temp * x) % MOD; // dont forget to MOD answer power
        } else {                            // even
            return (temp * temp) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long evenInd = (n + 1) / 2;
        long long oddInd = n / 2;

        return (myPow(5, evenInd) * myPow(4, oddInd)) % MOD;
    }
};

//see notes recursion for logic
