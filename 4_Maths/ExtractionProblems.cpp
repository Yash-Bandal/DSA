/*
Operations on Extracted digits from number
*/

//1 Count
#include <iostream>
#include <cmath> // for abs function

int countDigits(int num) {
    // Handle the edge case where num is 0
    if (num == 0) {
        return 1;
    }

    // Convert to a positive value if it's negative
    num = abs(num);

    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }

    return count;
}

int main() {
    int num = 12345;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    num = -9876;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    num = 0;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    return 0;
}'


  //2 Reverse a number 

  #include <iostream>
#include <cmath> // for abs function

int countDigits(int num) {
    // Handle the edge case where num is 0
    if (num == 0) {
        return 1;
    }

    // Convert to a positive value if it's negative
    num = abs(num);

    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }

    return count;
}

int main() {
    int num = 12345;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    num = -9876;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    num = 0;
    std::cout << "Number of digits in " << num << " is " << countDigits(num) << std::endl;

    return 0;
}


//3 Palindrome
class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers
        if (x < 0) {
            return false;
        }
        
        // Handle single-digit numbers (they are palindromes)
        if (x > -10 && x < 10) {
            return true;
        }

        int original = x;
        long reversed = 0;  // Use long to handle overflow cases
        int lastDigit;

        while (x > 0) {
            lastDigit = x % 10;
            reversed = reversed * 10 + lastDigit;
            x = x / 10;
        }

        // Compare the original number with the reversed number
        return original == reversed;
    }
};



//4 Armstron
/*
An Armstrong number (also known as a narcissistic number) is a number that is equal to
the sum of its own digits raised to the power of the number of digits. For example, 153 is an Armstrong number because 1 cub+ 5 cub+ 3 cub=153
1634=1^4+6^4+3^4+4^4=1634
153, 370, 371 and 407 are an Armstrong number list 
 4 digits are 1634, 8208, and 9474 ...raise to power 4 each digit

*/
#include <iostream>
#include <cmath> // For pow function

using namespace std;

bool isArmstrong(int x) {
    int original = x;
    int sum = 0;
    int numDigits = 0;
    int temp = x;

    // Calculate the number of digits
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    // Calculate the sum of each digit raised to the power of the number of digits
    temp = x;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == original;
}

int main() {
    int x = 1634; // Changed to a number that is an Armstrong number
    

    if (isArmstrong(x)) {
        cout << x << " is an Armstrong number." << endl;
    } else {
        cout << x << " is not an Armstrong number." << endl;
    }

    return 0;
}







