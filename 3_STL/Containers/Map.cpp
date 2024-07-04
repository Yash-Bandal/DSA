#include <iostream>
#include <map>

using namespace std;

int main() {
    // A map is an associative container that stores elements as key-value pairs in sorted order by key.
    map<int, string> myMap;

    // Insert elements into the map
    myMap[1] = "one";  // {1, "one"}
    myMap[3] = "three";  // {1, "one"}, {3, "three"}
    myMap[2] = "two";  // {1, "one"}, {2, "two"}, {3, "three"}

    // Insert using insert() method
    myMap.insert({4, "four"});  // {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}

    // Print elements of the map
    cout << "Map elements: " << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // Map elements:
    // 1: one
    // 2: two
    // 3: three
    // 4: four

    // Find an element by key
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        cout << "Element found: " << it->first << ": " << it->second << endl;  // Output: Element found: 2: two
    } else {
        cout << "Element not found." << endl;
    }

    // Remove an element by key
    myMap.erase(3);  // {1, "one"}, {2, "two"}, {4, "four"}

    // Print elements of the map after removal
    cout << "Map elements after removing key 3: " << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // Map elements after removing key 3:
    // 1: one
    // 2: two
    // 4: four

    // Check the size of the map
    cout << "Size of the map: " << myMap.size() << endl;  // Output: Size of the map: 3

    // Check if the map is empty
    cout << "Is the map empty? " << (myMap.empty() ? "Yes" : "No") << endl;  // Output: Is the map empty? No

    // Demonstrate lower_bound and upper_bound
    auto lb = myMap.lower_bound(2);  // Points to the first element not less than 2
    auto ub = myMap.upper_bound(2);  // Points to the first element greater than 2

    cout << "Lower bound for key 2: ";
    if (lb != myMap.end()) {
        cout << lb->first << ": " << lb->second << endl;  // Output: Lower bound for key 2: 2: two
    } else {
        cout << "No lower bound found." << endl;
    }

    cout << "Upper bound for key 2: ";
    if (ub != myMap.end()) {
        cout << ub->first << ": " << ub->second << endl;  // Output: Upper bound for key 2: 4: four
    } else {
        cout << "No upper bound found." << endl;
    }

    return 0;
}
