#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//decreent loop
//Function to compute GCD using Euclidean algorithm
int gcd(int a, int b)
{
    int gcd = 1;
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break; // you forget this  //no else needed
        }
    }
    return gcd;
}
 

 //increment loop
// int gcd(int a, int b)
// {
//     int gcd = 1;
//     for (int i =1; i <= min(a,b); i++)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             gcd = i;

//         }
//     }
//     return gcd;
// }

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
