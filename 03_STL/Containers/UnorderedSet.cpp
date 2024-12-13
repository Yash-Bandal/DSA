#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // An unordered_set is an associative container that contains unique elements in no particular order.
    unordered_set<int> us;

    // Add elements to the unordered_set
    us.insert(5);
    us.insert(3);
    us.insert(8);
    us.insert(1);
    us.insert(7);
    us.insert(5);  // Duplicate element, will not be added

    // Print elements of the unordered_set
    cout << "Unordered set elements: ";
    for (int value : us) {
        cout << value << " ";
    }
    cout << endl;  // Output could be: Unordered set elements: 8 1 3 5 7 (order may vary)

    // Check if an element is in the unordered_set
    if (us.find(3) != us.end()) {
        cout << "Element 3 found in the unordered set." << endl;  // Output: Element 3 found in the unordered set.
    } else {
        cout << "Element 3 not found in the unordered set." << endl;
    }

    // Remove an element from the unordered_set
    us.erase(3);

    // Print elements of the unordered_set after removal
    cout << "Unordered set elements after removing 3: ";
    for (int value : us) {
        cout << value << " ";
    }
    cout << endl;  // Output could be: Unordered set elements: 8 1 5 7 (order may vary)

    // Size of the unordered_set
    cout << "Size of the unordered set: " << us.size() << endl;  // Output: Size of the unordered set: 4

    return 0;
}
