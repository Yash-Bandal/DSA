#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create a multimap with some key-value pairs
    multimap<int, string> mmp;

    // Insert elements into the multimap
    mmp.insert({1, "one"});
    mmp.insert({2, "two"});
    mmp.insert({2, "deux"});
    mmp.insert({3, "three"});
    mmp.insert({3, "tres"});
    mmp.insert({4, "four"});

    // Print elements of the multimap
    cout << "Multimap elements: " << endl;
    for (auto pair : mmp) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // Multimap elements:
    // 1: one
    // 2: two
    // 2: deux
    // 3: three
    // 3: tres
    // 4: four

    // Find elements with a specific key
    cout << "Elements with key 2: " << endl;
    auto range = mmp.equal_range(2);
    for (auto i = range.first; i != range.second; i++)
     {
        cout << i->first << ": " << i->second << endl;
    }

    //or

    cout << "Elements with key 2(bound): " << endl;
    for (auto i = mmp.lower_bound(2); i != mmp.upper_bound(2); i++)
     {
        cout << i->first << ": " << i->second << endl;
    }
    // Output:
    // Elements with key 2:
    // 2: two
    // 2: deux

    // Remove elements with a specific key
    mmp.erase(3);  // Removes all elements with key 3

    // Print elements of the multimap after removal
    cout << "Multimap elements after removing key 3: " << endl;
    for (auto pair : mmp) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // Multimap elements after removing key 3:
    // 1: one
    // 2: two
    // 2: deux
    // 4: four

    // Check the size of the multimap
    cout << "Size of the multimap: " << mmp.size() << endl;  // Output: Size of the multimap: 4

    // Check if the multimap is empty
    cout << "Is the multimap empty? " << (mmp.empty() ? "Yes" : "No") << endl;  // Output: Is the multimap empty? No

    return 0;
}
