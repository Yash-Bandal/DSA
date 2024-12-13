#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Create an unordered_map with some key-value pairs
    unordered_map<int, string> ump;

    // Insert elements into the unordered_map
    ump[1] = "one";
    ump[3] = "three";
    ump[2] = "two";
    ump[4] = "four";

    // Print elements of the unordered_map
    cout << "Unordered map elements: " << endl;
    for (auto pair : ump) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output may vary due to unordered nature, for example:
    // Unordered map elements:
    // 1: one
    // 2: two
    // 3: three
    // 4: four

    // Find an element by key
    auto it = ump.find(2);
    if (it != ump.end()) {
        cout << "Element found: " << it->first << ": " << it->second << endl;  // Output: Element found: 2: two
    } else {
        cout << "Element not found." << endl;
    }

    // Remove an element by key
    ump.erase(3);  // Removes the element with key 3

    // Print elements of the unordered_map after removal
    cout << "Unordered map elements after removing key 3: " << endl;
    for (auto pair : ump) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output may vary due to unordered nature, for example:
    // Unordered map elements after removing key 3:
    // 1: one
    // 2: two
    // 4: four

    // Check the size of the unordered_map
    cout << "Size of the unordered_map: " << ump.size() << endl;  // Output: Size of the unordered_map: 3

    // Check if the unordered_map is empty
    cout << "Is the unordered_map empty? " << (ump.empty() ? "Yes" : "No") << endl;  // Output: Is the unordered_map empty? No

    return 0;
}
