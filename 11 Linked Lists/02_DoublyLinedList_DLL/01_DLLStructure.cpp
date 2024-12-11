#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{ // or class Node
public:
    int data;
    Node *next;
    Node *prev;

public:
    // Constructor to initialize data and next pointer
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // auto assing 2 nptrs..
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev); // next is nullptr and prev is head ..first    <-
        prev->next = temp;                            //                                               ->
        prev = prev->next;
    }
    return head;
}

void printLL(Node *tail)
{ // initially we pass head..head = tail for first node that moves till last
    while (tail != NULL)
    {
        cout << tail->data << " ";
        tail = tail->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = convertArrToLL(arr);  //  NULL <- 1 <-> 2 <-> 3 <-> 4 -> NULL
    printLL(head);
    return 0;
}
