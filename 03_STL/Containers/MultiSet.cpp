#include <iostream>
#include <set>

using namespace std;

int main() {
    // A multiset is an associative container that stores multiple elements in sorted order, allowing duplicates.
    multiset<int> ms;

    // Add elements to the multiset
    ms.insert(5);  // [5]
    ms.insert(3);  // [3 5]
    ms.insert(8);  // [3 5 8]
    ms.insert(1);  // [1 3 5 8]
    ms.insert(3);  // [1 3 3 5 8]
    ms.insert(5);  // [1 3 3 5 5 8]

    // Print elements of the multiset
    cout << "Multiset elements: ";
    for (int value : ms) {
        cout << value << " ";
    }
    cout << endl;  // Output: Multiset elements: 1 3 3 5 5 8

    // Find the number of occurrences of an element
    int count3 = ms.count(3);
    cout << "Count of element 3: " << count3 << endl;  // Output: Count of element 3: 2

    // Find an element in the multiset
    auto it = ms.find(5);
    if (it != ms.end()) {
        cout << "Element 5 found: " << *it << endl;  // Output: Element 5 found: 5
    } else {
        cout << "Element 5 not found." << endl;
    }

    // Erase only one instance of an element from the multiset
    auto it3 = ms.find(3);
    if (it3 != ms.end()) {
        ms.erase(it3);  // Removes one instance of 3
    }

    // Print elements of the multiset after erasing one instance of 3
    cout << "Multiset elements after erasing one 3: ";
    for (int value : ms) {
        cout << value << " ";
    }
    cout << endl;  // Output: Multiset elements after erasing one 3: 1 3 5 5 8

    // Use lower_bound and upper_bound
    auto lb = ms.lower_bound(5);  // Points to the first element >= 5
    if (lb != ms.end()) {
        cout << "Lower bound of 5: " << *lb << endl;  // Output: Lower bound of 5: 5
    } else {
        cout << "Lower bound of 5 not found." << endl;
    }

    auto ub = ms.upper_bound(5);  // Points to the first element > 5
    if (ub != ms.end()) {
        cout << "Upper bound of 5: " << *ub << endl;  // Output: Upper bound of 5: 8
    } else {
        cout << "Upper bound of 5 not found." << endl;
    }

    return 0;
}
