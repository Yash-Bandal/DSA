
//Array

#include <iostream>
#include <algorithm>  // For std::lower_bound and std::upper_bound

using namespace std;
 
int main() {
            // 0  1  3  3  4  5  6  7 .....7 is ahead index..if value greater than 8 entered
    int a[] = {1, 2, 3, 4, 5, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);  // Number of elements in the array

    // Use lower_bound to find the index of the first element not less than 3
    int lb = lower_bound(a, a + n, 3)-a;
    int lb1 = lower_bound(a, a + n, 6)-a;  
    int lb2 = lower_bound(a, a + n, 9)-a;  //6 is ahead of 5..thus imagine index 7

    //to print array ele..print a[lb]

    cout << "Lower bound index of 3[present number]: " << lb << endl;  // Output: Lower bound index of 3: 2
    cout << "Lower bound index of 6[absent number]: " << lb1 << endl;  // Output: Lower bound index of 3: 2
    cout << "Lower bound index of 9[number ahead of index]: " << lb2 << endl;  // Output: Lower bound index of 3: 2

    // Use upper_bound to find the index of the first element greater than 3
    int ub = upper_bound(a, a + n, 3)-a;
    int ub1 = upper_bound(a, a + n, 6)-a;
    int ub2 = upper_bound(a, a + n, 9)-a;

cout<<endl;
    // Output the index for upper bound
    cout << "Upper bound index of 3: " << ub << endl;  // Output: Upper bound index of 3: 3
    cout << "Upper bound index of 6: " << ub1 << endl;  // Output: Upper bound index of 3: 3
    cout << "Upper bound index of 9: " << ub2 << endl;  // Output: Upper bound index of 3: 3

    return 0;
}


//Sets
#include <iostream>
#include <set>

using namespace std;

int main() {
    // Initialize the set with elements
    set<int> st = {10, 20, 30, 40, 50};  // [10, 20, 30, 40, 50]


    // Find the lower bound of an element
    auto lb = st.lower_bound(25);  // Iterator to the first element not less than 25
    if (lb != st.end()) {
        cout << "Lower bound of 25: " << *lb << endl;  // Output: Lower bound of 25: 30
    } 
    else {
        cout << "Lower bound of 25 not found." << endl;
    }

    // Find the upper bound of an element
    auto ub = st.upper_bound(25);  // Iterator to the first element greater than 25
    if (ub != st.end()) {
        cout << "Upper bound of 25: " << *ub << endl;  // Output: Upper bound of 25: 30
    } 
    else {
        cout << "Upper bound of 25 not found." << endl;
    }

    // Find the lower bound and upper bound of an element that is present in the set
    auto lb2 = st.lower_bound(30);  // Iterator to the first element not less than 30
    auto ub2 = st.upper_bound(30);  // Iterator to the first element greater than 30
 

    if (lb2 != st.end()) {
        cout << "Lower bound of 30: " << *lb2 << endl;  // Output: Lower bound of 30: 30
    } else {
        cout << "Lower bound of 30 not found." << endl;
    }

    if (ub2 != st.end()) {
        cout << "Upper bound of 30: " << *ub2 << endl;  // Output: Upper bound of 30: 40
    } else {
        cout << "Upper bound of 30 not found." << endl;
    }

    return 0;
}

