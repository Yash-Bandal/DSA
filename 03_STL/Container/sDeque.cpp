#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq = {1, 2, 3, 4, 5};

    // Print elements of the deque
    cout << "Initial deque: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    // Add elements to the front and back
    dq.push_front(0); // Add 0 to the front
    dq.push_back(6);  // Add 6 to the back

    // Print elements after additions
    cout << "Deque after adding elements: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    // Remove elements from the front and back
    dq.pop_front(); // Remove element from the front
    dq.pop_back();  // Remove element from the back

    // Print elements after removals
    cout << "Deque after removing elements: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    // Access elements using random access
    cout << "Element at index 2: " << dq[2] << endl;

    // Insert an element at a specific position
    auto it = dq.begin();
    advance(it, 2); // Move iterator to the third position (0-based index)
    dq.insert(it, 10); // Insert 10 at the third position

    // Print elements after insertion
    cout << "Deque after inserting element: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    // Remove a specific element
    dq.erase(it); // Remove the element at the current iterator position

    // Print elements after removing a specific element
    cout << "Deque after removing element: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
