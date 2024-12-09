#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;

public:
    // Constructor to initialize data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);  //we declare head every time
    Node *mover = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;  // mover pointing to next node
        mover = mover->next; // moving mover to next node
        // mover=temp; //or above line..any
    }
    return head;
}


int main() {
    vector<int> arr = {12, 5, 6, 4};

    /*
       Call the conversion function to get the linked list head.
       The linked list will look like this:
       12 -> 5 -> 6 -> 4 -> NULL
    */
    Node* head = convertArrToLL(arr);

    /*
       Print the data of the head node.
       Output will be: 12
    */
    cout << head->data << endl;

    return 0;
}

/*
   Visualization:

   Input Array: {12, 5, 6, 4}
   Linked List Construction:
   Step 1: Create head -> Node(12)
   Step 2: Add Node(5), link to head -> 12 -> 5
   Step 3: Add Node(6), link to previous -> 12 -> 5 -> 6
   Step 4: Add Node(4), link to previous -> 12 -> 5 -> 6 -> 4
   Final Linked List: 12 -> 5 -> 6 -> 4 -> NULL
*/

/*
12
*/
