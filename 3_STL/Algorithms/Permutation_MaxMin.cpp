#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main() {
    // Built-in population count example
    unsigned int x = 29; // Binary: 11101
    int count = __builtin_popcount(x);
    cout << "Number of set bits in " << x << " is " << count << endl;

    // Permutations of a string
    string s = "231";
    vector<string> permutations;

    // Sort the string to ensure permutations are generated in lexicographical order  123
    sort(s.begin(), s.end());

    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << "Permutations of the string '123' are:" << endl;
    for ( auto perm : permutations) {
        cout << perm << endl;
    }


   int a = 10, b = 20;
    int maximum = max(a, b);
    int minimum = min(a, b);
    cout << "Maximum of " << a << " and " << b << " is " << maximum << endl;
    cout << "Minimum of " << a << " and " << b << " is " << minimum << endl;


    int arr[]={1,5,8,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    int maxi=*max_element(arr,arr+n);
    int mini=*min_element(arr,arr+n);
    //int nu=max(arr);  //not exist

    cout<<"Max Element is :"<<maxi<<endl;  //8
    cout<<"Min Element is :"<<mini<<endl;   //1

       // Example usage of max and min with arrays
    array<int, 5> arr4 = {4, 1, 3, 5, 2};      //include<array>
    int maximum = *max_element(arr4.begin(), arr4.end());
    int minimum = *min_element(arr4.begin(), arr4.end());
    cout << "Maximum element in the array is " << maximum << endl;
    cout << "Minimum element in the array is " << minimum << endl;



    //usecases in competitive pro
    // where only max ele is eeded...the same var is updated
        // Updating a variable using max

    int var = 10;
    int newValue = 20;
    var = max(var, newValue);
    cout << "Updated var using max: " << var << endl; // Output: 20

    // Updating a variable using min
    int varMin = 15;
    int newMinValue = 5;
    varMin = min(varMin, newMinValue);
    cout << "Updated varMin using min: " << varMin << endl; // Output: 5
    

    return 0;
}
