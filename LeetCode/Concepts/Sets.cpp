#include <iostream>
#include <set>
using namespace std;

int main() {
    // Create a set of integers
    set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(2);  // Duplicate element, will not be added

    // Display the elements in the set
    cout << "Set elements (sorted and unique):" << endl;
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Check if a number is present in the set
    int num = 3;
    if (mySet.find(num) != mySet.end()) {
        cout << num << " is present in the set." << endl;
    } else {
        cout << num << " is not present in the set." << endl;
    }

    // Erase an element
    mySet.erase(5);
    cout << "After erasing 5, set elements:" << endl;
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Check size of the set
    cout << "Set size: " << mySet.size() << endl;

    // Check if the set is empty
    cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << endl;

    // Clear the set
    mySet.clear();
    cout << "After clearing, is the set empty? " << (mySet.empty() ? "Yes" : "No") << endl;

    return 0;
}


/*
Set elements (sorted and unique):
1 2 3 5 8
3 is present in the set.
After erasing 5, set elements:
1 2 3 8
Set size: 4
Is the set empty? No
After clearing, is the set empty? Yes

*/

-----------
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Initialize a vector with some elements (including duplicates)
    vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 1, 3, 8, 8};

    // Create an empty set to store unique elements
    set<int> mySet;

    // Store elements from the vector into the set
    for (int num : vec) {
        mySet.insert(num);  // Duplicates will be automatically discarded
    }

    // Display the elements in the set
    cout << "Set elements (unique and sorted):" << endl;
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

/*
Set elements (unique and sorted):
1 2 3 4 5 6 8

*/
