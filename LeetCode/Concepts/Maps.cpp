#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string, int> mpp = {
        {"Misal", 3},
        {"VadaPav", 5},
        {"Lassi", 2}
    };


    cout << "Menu: Misal, VadaPav, Lassi" << endl;


    string targetKey;
    cout << "Enter menu item to check inventory: ";
    cin >> targetKey;


    if (mpp.find(targetKey) != mpp.end()) {
        cout << "Yes, we have " << mpp.find(targetKey)->second << " " << targetKey  << endl;
    } else {
        cout << "No, the item is not available." << endl;
    }

    return 0;
}

/*
Menu: Misal, VadaPav, Lassi
Enter menu item to check inventory: Misal
Yes, we have 3 Misal .

*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    // Initialize a map
    map<string, int> mpp = {
        {"Misal", 3},
        {"VadaPav", 5},
        {"Lassi", 2}
    };

    // Insert a new element
    mpp["PavBhaji"] = 7;

    // Access an element using the [] operator
    cout << "Misal count: " << mpp["Misal"] << endl;

    // Check if a key exists
    if (mpp.find("Lassi") != mpp.end()) {
        cout << "Lassi exists!" << endl;
    } else {
        cout << "Lassi does not exist!" << endl;
    }

    // Iterate over the map and print key-value pairs
    cout << "Menu and inventory:" << endl;
    for (const auto& pair : mpp) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Remove an element
    mpp.erase("VadaPav");

    // Print after removal
    cout << "After removing VadaPav:" << endl;
    for (const auto& pair : mpp) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
/*
Misal count: 3
Lassi exists!
Menu and inventory:
Misal : 3
VadaPav : 5
Lassi : 2
PavBhaji : 7
After removing VadaPav:
Misal : 3
Lassi : 2
PavBhaji : 7

*/
