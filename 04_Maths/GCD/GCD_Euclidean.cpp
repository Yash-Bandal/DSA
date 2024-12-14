#include <iostream>
#include <algorithm> // For std::min

using namespace std;

// Function to compute GCD using Euclidean algorithm

//can also use gcd(a,b)=gcd(a-b,b)  ..but high TC

// // 1 gcd(a,b)=gcd(a%b=remainder,b)
// int gcd(int a, int b) {
//     while (b != 0) {
//         int r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }


 // 2 gcd(a,b)=gcd(a%b,b)
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    // At this point, one of a or b is 0
    if (a == 0){
        return b;
    }else{
        return a;
    }
}
int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
