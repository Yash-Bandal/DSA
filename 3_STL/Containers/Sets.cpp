#include <iostream>
#include <set>

using namespace std;

int main()
{

    // A set is an associative container that stores unique elements in a sorted order.
    set<int> mySet;

    // Add elements to the set
    mySet.insert(5); // [5]
    mySet.insert(3); // [3 5]
    mySet.insert(8); // [3 5 8]
    mySet.insert(1); // [1 3 5 8]
    mySet.insert(7); // [1 3 5 7 8]
    mySet.insert(5); // [1 3 5 7 8]  // Duplicate element, will not be added

    // Find an element in the set
    auto it1 = mySet.find(3);
    // Check if the element is found
    if (it1 != mySet.end())
    {
        // Print the value pointed to by the iterator
        cout << "Element  " << (*it1) << " found: " << endl; // Output: Element found: 3
    }
    else
    {
        cout << "Element " << (*it1) << " not found." << endl;
    }

    bool var = mySet.count(3);
    bool var1 = mySet.count(88);
    int var2 = mySet.count(5);
    // bool var2= mySet.find(3); // not posssible
    cout << var << endl;  // print 1
    cout << var1 << endl; // print 0
    cout << var2 << endl; // print 1 or 0 only..even if 5 entered two times..set has uniq eles

    // Elements are automatically sorted in ascending order when stored in a set. internal Heap/Tree
    cout << "Set elements: ";
    for (int value : mySet)
    {
        cout << value << " ";
    }
    cout << endl; // Output: Set elements: 1 3 5 7 8

    cout << "Is 3 in the set? " << (mySet.count(3) ? "Yes" : "No") << endl; // Output: Is 3 in the set? Yes
    cout << "Is 6 in the set? " << (mySet.count(6) ? "Yes" : "No") << endl; // Output: Is 6 in the set? No

    // Remove an element from the set
    mySet.erase(3); // [1 5 7 8]

    cout << "Set elements after removing 3: ";
    for (int value : mySet)
    {
        cout << value << " ";
    }
    cout << endl; // Output: Set elements after removing 3: 1 5 7 8

    // Find an element in the set
    // The find function returns an iterator to the element if found, or mySet.end() if not found.
    auto it = mySet.find(8);
    if (it != mySet.end())
    {
        cout << "Element 8 found in the set." << endl; // Output: Element 8 found in the set.
    }
    else
    {
        cout << "Element 8 not found in the set." << endl;
    }

    // Size
    cout << "Size of the set: " << mySet.size() << endl; // Output: Size of the set: 4

    cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << endl; // Output: Is the set empty? No

    set<int> st = {10, 20, 30, 40, 50}; // [10, 20, 30, 40, 50]
    auto it2 = st.find(20);             // Iterator to element 20   //imagine it2 as index 1 of array..inclusive..deleted
    auto it3 = st.find(30);             // Iterator to element 30  //imagine it3 as index 2...exclusive..not deleted

    // Erase elements from it2 to it3 (exclusive of it3)
    st.erase(it2, it3); // Erases element 20

    // Print the elements of the set
    cout << "Set elements after erasing from it2 to it3: ";
    for (int value : st)
    {
        cout << value << " ";
    }
    cout << endl; // Output: Set elements after erasing from it2 to it3: 10 30 40 50

    return 0;
}
