/*
Concepts :
Note we declare Node* head and Node*next..they are pointers..

x->y is dereferencing process..
head->next = temp...means a pointer pointing to next Node
head-> data = integer value

thus x->y can be a ptr value or a data value depending on y value..
x is ptr  if y data x->y integer if y ptr (next) x->y also ptr
*/



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
       // Constructor
    Node(int data1) {
        data = data1;
        next = nullptr;
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
  // Node* y = new Node(arr[0], nullptr);  

    //or
    Node x = Node(arr[0], nullptr);
    Node* y = &x;                           // Create a pointer 'y' pointing to the Node 'x'
    cout << "Address of y: " << y << endl;  // Prints the memory address of 'y'
    cout << "y->data: " << y->data << endl; // Access 'data' using '->'
  // cout<<y.data<<endl;                    //cant print y.data its not object

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
