//Imp basic palindrome
#include <bits/stdc++.h>

using namespace std;
// Consider the string "A man, a plan, a canal: Panama" here there are spaces not alphanumeric
bool isPalindrome(string s)
{

    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        // we need this to ensure if there are no spaces
        /*Second Iteration:

left = 1 (pointing to space ' ')
right = 28 (pointing to 'm')
isalnum(s[left]) returns false (since space is not alphanumeric).
Increment left to 2 to skip the space.
Third Iteration:

left = 2 (pointing to 'm')
right = 28 (pointing to 'm')*/
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
int main()
{

    string str = "ABCDCBA";
    bool ans = isPalindrome(str);

    if (ans == true)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    return 0;
}


//------------ReCuRsIoN-------------------- 


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

//without using n iterations using half iteratons

#include <iostream>
using namespace std;

bool palindrome(int i, string& s){
    int n=s.length();
    
    // Base Condition
    // If i exceeds half of the string means all the elements 
    // are compared, we return true.
    if(i>=n/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[n-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(i+1,s);
}

int main() {
	
	// Example string.
	string s = "madam";
	cout<<palindrome(0,s);
	cout<<endl;
	return 0;
}
