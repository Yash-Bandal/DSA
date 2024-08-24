//Brute Force
/*
The inner loop uses N-1 instead of N because the array a 
contains only N-1 elements (as one number is missing). Therefore, we iterate over the indices 0 to N-2
*/
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N+1; i++) {   //

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N ; j++) {          
            if (a[j] == i) {   //not arr[i]  its i

                // i is present in the array:
                flag = 1;
                break;   //you forget this..imagine the looping every time
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

int main()
{
    vector<int> a = {1, 2, 3,4};
    int N=a.size();
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}


//Better approach
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>&a, int N) {

    int hash[N + 2] = {0}; //hash array starts from 0 + we need 1 space extra

    // storing the frequencies:
    for (int i = 0; i < N ; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N+1; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}


int main()
{
    vector<int> a = {1, 2, 3,4};
    int N=a.size();
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
/*
first full hash arry is created

0:0  ..not iterated so forget this
1:1  //we iterate and check from 1 ..not 0 but create a hash array of size 6..as bydefault 0 is included and we want 1 extra (to handle missing one)
2:1 .. count is 1 continue counting
3:1
4:1
5:0   ...when count is 0 return that number as its missing..

*/

//optimal 1



#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;  

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

//Optimal 2 - XOR
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{

    int xor1 = 0, xor2 = 0;

    // Run Xor for complete set of array without missing num    ..1 to N
    for (int i = 1; i <= N; i++)
    {
        xor1 = xor1 ^ i;
    }
    // Run Xor for complete set of array with missing num     ..index 0 to N-1 n is not size here observe
    for (int i = 0; i < N - 1; i++) // array iteration
    {
        xor2 = xor2 ^ a[i];
    }
    return xor1 ^ xor2;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
/* Takes TC=O(2*N)  reduce it by using single loop */  


