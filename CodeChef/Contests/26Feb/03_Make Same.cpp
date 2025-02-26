#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases

    while (t--) {
        int N;
        cin >> N;  // Read N (length of each string)

        // Read three binary strings
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        // Count the number of '1's in each string
        int a[3] = {0, 0, 0};
        for (int i = 0; i < N; i++) {
            if (s1[i] == '1') a[0]++;
            if (s2[i] == '1') a[1]++;
            if (s3[i] == '1') a[2]++;
        }

        int totalOnes = a[0] + a[1] + a[2];

        // Case 1: Already uniform 
        /*
        eg 
        000     111
        000     111
        000     111
        total 1 = 0 or total 1 = 3*3 = 9
        */
        if (totalOnes == 0 || totalOnes == 3 * N) {
            cout << "0" << endl;
        } 
        
        // Case 2: We can make all strings same
        /*
        eg
        100
        000
        011
        here a[3] = {1 , 0 , 2}
        ie max(1,0,2) = max(1,max(0,2))
        here third 
        cout<<3-2 == 1
        */
        else if (totalOnes == N) {
            // Find the string with the most '1's
            int maxOnes = max(a[0], max(a[1], a[2]));
            cout << (N - maxOnes) << endl;
        } 
        
        // Case 3: Exactly 2N ones
        else if (totalOnes == 2 * N) {
            // Find the string with the least '1's
            int minOnes = min(a[0], min(a[1], a[2]));
            cout << minOnes << endl;
        } 
        
        // Case 4: Not possible
        else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
