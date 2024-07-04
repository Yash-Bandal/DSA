#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Add elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Print elements of the queue
    cout << "Initial queue: ";
    queue<int> tempQueue = q; // Copy the queue to avoid modifying the original
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    // Remove an element from the front
    q.pop();

    // Print elements after removal
    cout << "Queue after removing one element: ";
    tempQueue = q; // Copy the queue to avoid modifying the original
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    // Access the front and back elements
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    return 0;
}
