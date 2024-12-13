#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create a stack of integers
    stack<int> myStack;

    // Add elements to the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Print elements of the stack
    cout << "Stack elements (top to bottom): ";
    stack<int> tempStack = myStack; // Copy the stack to avoid modifying the original
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Access the top element
    cout << "Top element: " << myStack.top() << endl;

    // Remove the top element
    myStack.pop();

    // Print elements after removal
    cout << "Stack after popping the top element: ";
    tempStack = myStack; // Copy the stack to avoid modifying the original
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    // Print the size of the stack
    cout << "Size of the stack: " << myStack.size() << endl;

    return 0;
}
