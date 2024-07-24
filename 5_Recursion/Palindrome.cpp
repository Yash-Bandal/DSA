#include <iostream>
using namespace std;

bool isPalindrome(char ch[], int s, int e) {
    if (s >= e) {  // means either crossed or single letter
        return true;
    }
    if (ch[s] != ch[e]) {
        return false;
    }
    return isPalindrome(ch, s + 1, e - 1);
}

int main() {
    char ch[] = "MAAM";
    int len = sizeof(ch) / sizeof(ch[0]) - 1;  // Calculate the length of the string excluding the null terminator

    cout << (isPalindrome(ch, 0, len - 1) ? "True" : "False");  // Correct end index
    return 0;
}
