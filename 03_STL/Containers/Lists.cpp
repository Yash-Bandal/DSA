#include<bits/stdc++.h>
#include <iostream>
// #include <list>

using namespace std;

int main() {
    // Create a list of integers
    list<int> ls = {1, 2, 3, 4, 5};

    // Print elements of the list
    cout << "Initial list: ";
    for (int value : ls) {
        cout << value << " ";
    }
    cout << endl;

    // Add elements to the front and back
    ls.push_front(0);
    ls.push_back(6);

    // Print elements after additions
    cout << "List after adding elements: ";
    for (int value : ls) {
        cout << value << " ";
    }
    cout << endl;

    // Remove elements from the front and back
    ls.pop_front();
    ls.pop_back();

    // Print elements after removals
    cout << "List after removing elements: ";
    for (int value : ls) {
        cout << value << " ";
    }
    cout << endl;

    // Insert an element in the middle
    auto it = ls.begin();
    advance(it, 2); // Move iterator to the third position
    ls.insert(it, 10);

    //ls.insert(ls.begin()+2, 10);  //cant do thislike vactor as biidirectional iterators

    // Print elements after insertion
    cout << "List after inserting element: ";
    for (int value : ls) {
        cout << value << " ";
    }
    cout << endl;

    // Remove a specific element
    ls.remove(3);

    // Print elements after removing a specific element
    cout << "List after removing element 3: ";
    for (int value : ls) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
