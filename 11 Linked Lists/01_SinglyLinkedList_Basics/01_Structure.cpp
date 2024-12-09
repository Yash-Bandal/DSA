#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {   //or class Node
public:
    int data;
    Node* next;

public:
    // Constructor to initialize data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2, 5, 6, 4};

    // Creating a Node object (not using 'new')
    Node y1 = Node(arr[0], nullptr); 
  //xout<<y1<<endl; //not possible..as we cant print object directly
    cout << "y1 next: " << y1.next << endl; // Prints the 'next' pointer (nullptr for 0th index)
    cout << "y1 data: " << y1.data << endl; // Prints the 'data' value

    // Creating a Node dynamically (using 'new')
    Node* y = new Node(arr[0], nullptr);  
    cout << "Address of y: " << y << endl; // Prints the memory address of 'y'
    cout << "y->data: " << y->data << endl; // Access 'data' using '->'
  // cout<<y.data<<endl;  //cant print y.data its not object

    // Note:
    // y.data is not valid as 'y' is a pointer, not an object.
    // Direct access requires '->', not '.'.

    return 0;
}

/*
y1 next:0
y1 data :2
0x1007f00
y->data : 2
*/
