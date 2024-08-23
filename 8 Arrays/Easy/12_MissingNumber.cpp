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

    int hash[N + 2] = {0}; //hash array

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
