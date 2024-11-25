#include <iostream>
using namespace std;
  
void printPattern(int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        { 
            cout << "* ";
        }
        cout << endl;
    }
} 
// * * * *
// * * * * 
// * * * *
// * * * *

void printPattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// *
// * *
// * * *
// * * * *

void printPattern3(int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << k << " ";
            k++;
        }
        cout << endl;
    }
}
// 0
// 1 2
// 3 4 5
// 6 7 8 9

void printPattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
// 0
// 1 1
// 2 2 2
// 3 3 3 3

void printPattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
// 1
// 1 2
// 1 2 3
// 1 2 3 4

void printPattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
// 1
// 2 2
// 3 3 3
// 4 4 4 4

void printPattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// * * * *
// * * *
// * *
// *

void printPattern8(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
// 1234
// 123
// 12
// 1

void printPattern9(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
// 1234
// 123
// 12
// 1

void printPattern10(int n)  //Remeber at i=0 and n=5 we have to print [4 1 4]..that is generate formula w.r.t i and n to print all 4 spaecs 1 *4 spc in continuos
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // For printing the stars in each row
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // For printing the spaces after the stars in each row
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
//      *
//     ***
//    *****
//   *******
//  *********

void printPattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // For printing the stars in each row
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        // For printing the spaces after the stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
// *********
//  *******
//   *****
//    ***
//     *

void printPattern12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // For printing the stars in each row
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // For printing the spaces after the stars in each row
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // For printing the stars in each row
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        // For printing the spaces after the stars in each row
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *

void printPattern13_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *

void printPattern13_2(int n)
{
    for (int i = 1; i <= (2 * n - 1); i++)  //n-one not i
    {
        int stars = i;
        if (i > n)
        {
            stars = (2 * n - i);  //n- i not one
        };

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *

void printPattern14(int n)  //easy
{ // my sol
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    cout << "0";
                }
                else
                {
                    cout << "1";
                }
            }
        }
        cout << endl;
    }

    int start = 1;

    //   // Outer loop for the no. of rows
    //   for(int i=0;i<n;i++){

    //       // if the row index is even then 1 is printed first
    //       // in that row.
    //       if(i%2 ==0) start = 1;

    //       // if odd, then the first 0 will be printed in that row.
    //       else start = 0;

    //       // We alternatively print 1's and 0's in each row by using
    //       // the inner for loop.
    //       for(int j=0;j<=i;j++){
    //           cout<<start;
    //           start = 1-start;  //alternate 1 0 1 0 loop run
    //       }

    //     // As soon as the numbers for each iteration are printed, we move to the
    //     // next row and give a line break otherwise all numbers
    //     // would get printed in 1 line.
    //     cout<<endl;
    //   }
}
// 1
// 01
// 101
// 0101
// 10101

void printPattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        // For printing the stars in each row
        for (int j = 1; j < 2 * n - (2 * i + 1); j++)
        {
            cout << " ";
        }
        // For printing the spaces after the stars in each row
        for (int j = i + 1; j > 0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
// 1      1
// 12    21
// 123  321
// 12344321

void printPattern16(int n)
{

    for (int i = 0; i < n; i++)
    {
        char c = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }

    // or

    //     for(int i=0;i<n;i++){

    //       // Inner loop will loop for i times and
    //       // print alphabets from A to A + i.
    //       for(char ch = 'A'; ch<='A'+i;ch++){
    //           cout<<ch<<" ";

    //       }
    //       // As soon as the letters for each iteration are printed, we move to the
    //       // next row and give a line break otherwise all letters
    //       // would get printed in 1 line.
    //       cout<<endl;

    //   }
}
// A
// A B
// A B C
// A B C D
// A B C D E

void printPattern17(int n)
{
    for (int i = n; i >= 0; i--)
    {
        char c = 'A';
        for (int j = 0; j < i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }

    // no decrement for alphabets inner loop
    //       for(int i=0;i<n;i++){

    //       // Inner loop will loop for i times and
    //       // print alphabets from A to A + (N-i-1).
    //       for(char ch = 'A'; ch<='A'+(N-i-1);ch++){
    //           cout<<ch<<" ";

    //       }
    //       // As soon as the letters for each iteration are printed, we move to the
    //       // next row and give a line break otherwise all letters
    //       // would get printed in 1 line.
    //       cout<<endl;

    //   }
}
// A B C D E
// A B C D
// A B C
// A B
// A

void printPattern18(int n)
{

    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}
// A
// B B
// C C C
// D D D D
// E E E E E

void printPattern19(int n)
{
    // Outer loop for the number of rows.
    for (int i = 0; i < n; i++)
    {

        // for printing the spaces.
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // for printing the characters.
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {

            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        // for printing the spaces again after characters.
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // As soon as the letters for each iteration are printed, we move to the
        // next row and give a line break otherwise all letters
        // would get printed in 1 line.
        cout << endl;
    }
}
//     A    
//    ABA   
//   ABCBA  
//  ABCDCBA 
// ABCDEDCBA

void printPattern20(int n)
{
    // Outer loop for the no. of rows.
    for (int i = 0; i < n; i++)
    {

        // Inner loop for printing the alphabets from
        // A + N -1 -i (i is row no.) to A + N -1 ( E in this case).
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {

            cout << ch << " ";
        }

        // As soon as the letters for each iteration are printed, we move to the
        // next row and give a line break otherwise all letters
        // would get printed in 1 line.
        cout << endl;
    }
}
// E
// D E
// C D E
// B C D E
// A B C D E

void printPattern21(int n)
{

    // for the upper half of the pattern.

    // initial spaces.
    int iniS = 0;
    for (int i = 0; i < n; i++)
    {

        // for printing the stars in the row.
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        // The spaces increase by 2 every time we hit a new row.
        iniS += 2;

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }

    // for lower half of the pattern

    // initial spaces.
    iniS = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // for printing the spaces in the row.
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        // for printing the stars in the row.
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // The spaces decrease by 2 every time we hit a new row.
        iniS -= 2;

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

void printPattern22(int n)
{

    int spaces = 2 * n - 2;

    // Outer loop for printing row.
    for (int i = 1; i <= 2 * n - 1; i++)
    {

        // stars for first half
        int stars = i;

        // stars for the second half.
        if (i > n)
            stars = 2 * n - i;

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // for printing the spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // for printing the stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
        if (i < n)
            spaces -= 2; // reduce spaces
        else
            spaces += 2;
    }
}
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *

void printPattern23(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 || i == (n - 1) || j == 0 || j == (n - 1))
                cout << "*";

            else
                cout << " ";
        }
        cout << endl;
    }
}
// *****
// *   *
// *   *
// *   *
// *****

void printPattern24(int n)
{
    for (int i = 0; i < 2*n-1; i++)
    {
        
        for (int j = 0; j < 2*n-1; j++)
        {
      int top = i;
             int bottom = j;
             int right = (2*n - 2) - j;
             int left = (2*n - 2) - i;
             
             // Min of 4 directions and then we subtract from n
             // because previously we would get a pattern whose border
             // has 0's, but we want with border N's and then decreasing inside.
             cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
           
        }
               
        cout << endl;
    }
}
// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5 

int main()
{
    int n = 5;
    // cout << "Enter the size of the pattern: ";
    // cin >> n;

    printPattern(n);
    printPattern2(n);
    printPattern3(n);
    printPattern4(n);
    printPattern5(n);
    printPattern6(n);
    printPattern7(n);
    printPattern8(n);
    printPattern9(n);
    printPattern10(n);
    cout << endl;
    printPattern11(n);
    printPattern12(n);
    printPattern13_1(n);
    printPattern13_2(n);
    printPattern14(n);
    printPattern15(n);
    printPattern16(n);
    printPattern17(n);
    printPattern18(n);
    printPattern19(n);
    printPattern20(n);
    printPattern21(n);
    printPattern22(n);
    printPattern23(n);
    printPattern24(n);

    return 0;
}
