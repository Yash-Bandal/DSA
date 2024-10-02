#include <iostream>
using namespace std;

// Function to print Pascal's Triangle
void printPascal(int n) {
    for (int line = 1; line <= n; line++) {
        int C = 1; // First value in a line is always 1
        for (int i = 1; i <= line; i++) {
            cout << C << " "; // Print current coefficient
            C = C * (line - i) / i; // Update C using Binomial Coefficient formula
        }
        cout << endl;
    }
}

int main() {
    int n = 5; // Number of rows
    printPascal(n);
    return 0;
}

/* Output for n = 5:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
*/


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Let's perform a dry run of the given code for n = 5:

Initialization:
The main function calls printPascal(n) with n = 5.
The printPascal function begins, where n = 5 means the function will print 5 rows.
-------------------------------------------------------------------------------
First Iteration (line = 1):
C = 1 (initial value for the first element).
Since line = 1, the inner loop runs for i = 1 (only one iteration).
Output: 1 (since C = 1).
No more iterations for this line, move to the next line.
Output after the first iteration:


1

 ------------------------------------------------------------------------------- 
Second Iteration (line = 2):
C = 1 (initial value for the first element).
The inner loop runs for i = 1 and i = 2 (two iterations).
For i = 1: Output C = 1, then update C = C * (2 - 1) / 1 = 1.
For i = 2: Output C = 1.
No more iterations for this line, move to the next line.
Output after the second iteration:


1
1 1

  -------------------------------------------------------------------------------
Third Iteration (line = 3):
C = 1 (initial value for the first element).
The inner loop runs for i = 1, i = 2, and i = 3 (three iterations).
For i = 1: Output C = 1, then update C = C * (3 - 1) / 1 = 2.
For i = 2: Output C = 2, then update C = C * (3 - 2) / 2 = 1.
For i = 3: Output C = 1.
No more iterations for this line, move to the next line.
Output after the third iteration:


1
1 1
1 2 1

  -------------------------------------------------------------------------------
Fourth Iteration (line = 4):
C = 1 (initial value for the first element).
The inner loop runs for i = 1, i = 2, i = 3, and i = 4 (four iterations).
For i = 1: Output C = 1, then update C = C * (4 - 1) / 1 = 3.
For i = 2: Output C = 3, then update C = C * (4 - 2) / 2 = 3.
For i = 3: Output C = 3, then update C = C * (4 - 3) / 3 = 1.
For i = 4: Output C = 1.
No more iterations for this line, move to the next line.
Output after the fourth iteration:


1
1 1
1 2 1
1 3 3 1

  -------------------------------------------------------------------------------
Fifth Iteration (line = 5):
C = 1 (initial value for the first element).
The inner loop runs for i = 1, i = 2, i = 3, i = 4, and i = 5 (five iterations).
For i = 1: Output C = 1, then update C = C * (5 - 1) / 1 = 4.
For i = 2: Output C = 4, then update C = C * (5 - 2) / 2 = 6.
For i = 3: Output C = 6, then update C = C * (5 - 3) / 3 = 4.
For i = 4: Output C = 4, then update C = C * (5 - 4) / 4 = 1.
For i = 5: Output C = 1.
No more iterations for this line, move to the next line.
  
Output after the fifth iteration:


1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
-------------------------------------------------------------------------------
  
Final Output:
The Pascal's Triangle for n = 5 is:


1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
