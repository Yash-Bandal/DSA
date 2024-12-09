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

int main()
{
    vector<int> arr = {12, 5, 6, 4};
    Node *head = convertArrToLL(arr);
    cout << head->data << endl;

    return 0;
}

/*
12
*/
