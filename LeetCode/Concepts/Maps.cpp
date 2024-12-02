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
