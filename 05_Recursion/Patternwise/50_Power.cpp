
// gives runtime error for large value of 'n'
//  class Solution {

// public:
//     double myPow(double x, int n) {
//         if (n == 1) {
//             return x;
//         } if (n == 0) {
//             return 1;
//         }

//         double temp = myPow(x, n - 1);

//         return x*temp;
//     }
// };


//Working optimied..if even power calculates half * half..every time..saving time
//see notes 

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
       if (n < 0) {
            if (n == INT_MIN) {
                // Avoid overflow by handling INT_MIN separately
                return 1 / (x * myPow(x, -(n + 1)));
            }
            return 1 / myPow(x, -n);
        }

        double temp = myPow(x, n / 2);

        if (n % 2 == 1) {
            return temp * temp * x;
        } else {
            return temp * temp;
        }
    }
};
/*
⚠️
read contrains 
-2^31 <= n <= 2^31-1
thus we need to handle INT_MIN that is -2^31
as prog cant handle it


thus in program give separate case for INT_MIN..by adding 1 to it


-2^31 = -2147483648
but we can handle -2147483647..as it lies within constraints
this -2147483648 + 1 = n+1 = −2147483647,
                      −(n+1)=2147483647

*/
