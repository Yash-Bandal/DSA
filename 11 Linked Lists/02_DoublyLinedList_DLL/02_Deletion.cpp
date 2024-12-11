#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{ // or class Node
public:
    int data;
    Node *next;
    Node *back;

public:
    // Constructor to initialize data and next pointer
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
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

Node *deleteHead(Node *head)
{
    // 1. edge case
    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }

    // 2. head ..1+ele DLL
    Node *prev = head;
    head = head->next; // move head 1 node ahead

    head->back = nullptr; // break the bond💔
    prev->next = nullptr; // delink the prev..seperate it

    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }

    Node *tail = head;

    // 1. traverse tail to last
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // 2. mark prev
    Node *newTail = tail->back;

    // 3. seperate the tail and delete
    newTail->next = nullptr;
    tail->back = nullptr;

    delete (tail);
    return head;
}

Node *deleteK(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    { // here reach enddd
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;
    if (prev == NULL && front == NULL)
    { // only one node in DLL
        delete temp;
        return NULL;
    }
    else if (prev == NULL)
    { // temp ch prev is NULL ie   `temp` is the head
        return deleteHead(head);
    }
    else if (front == NULL)
    { // temp ch front is NULL ie   `temp` is the tail
        return deleteTail(head);
    }
    else
    { // temp between ie `temp` is in the middle
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;

        delete temp;
    }

    return head;
}

void deleteNode(Node *temp)
{ // condition temp is ot head..possible but more conditions..
    Node *prev = temp->back;
    Node *front = temp->next;

    // 1. edge case temp is tail
    if (front == NULL)
    { // tail
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return; // void func
    }

    // 2. temp between
    prev->next = temp->next;
    front->back = temp->back;

    temp->back = temp->next = nullptr;
    free(temp);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convertArrToLL(arr); //  NULL <- 1 <-> 2 <-> 3 <-> 4 -> NULL
    printLL(head);

    cout << "\n=================== HEAD DELETION ====================" << endl;
    cout << "Head Deletion" << endl;

    cout << "\nBefore Delete Head :" << endl;
    printLL(head);

    head = deleteHead(head);

    cout << "\nAfter Delete Head : " << endl;
    printLL(head);

    cout << "\n=================== TAIL DELETION ====================" << endl;
    cout << "Tail Deletion" << endl;

    cout << "\nBefore Delete Tail :" << endl;
    printLL(head);

    head = deleteTail(head);

    cout << "\nAfter Delete Tail : " << endl;
    printLL(head);

    cout << "=================== K DELETION ====================" << endl;
    cout << "K Deletion" << endl;
    int k = 4;
    cout << "\nBefore " << k << "rd position Deletion :" << endl;
    printLL(head);

    head = deleteK(head, k);
    cout << "\n After " << k << "rd position Deletion :" << endl;
    printLL(head);

    cout << "=================== NODE DELETION ====================" << endl;
    cout << "Node Deletion" << endl;

    cout << "\nBefore Node  Deletion :" << endl;
    printLL(head);

    // head = deleteNode(head); not given here as we will have to take head to next..more more conditions
    Node *temp = head->next;
    deleteNode(temp);
    cout << "\n After  Node Deletion :" << endl;
    printLL(head);

    cout << endl;

    cout << endl;
    return 0;
}


/*
1 2 3 4 5 6 7 8 9 
=================== HEAD DELETION ====================
Head Deletion

Before Delete Head :
1 2 3 4 5 6 7 8 9 
After Delete Head : 
2 3 4 5 6 7 8 9 
=================== TAIL DELETION ====================
Tail Deletion

Before Delete Tail :
2 3 4 5 6 7 8 9 
After Delete Tail : 
2 3 4 5 6 7 8 =================== K DELETION ====================
K Deletion

Before 4rd position Deletion :
2 3 4 5 6 7 8 
 After 4rd position Deletion :
2 3 4 6 7 8 =================== NODE DELETION ====================
Node Deletion

Before Node  Deletion :
2 3 4 6 7 8 
 After  Node Deletion :
2 4 6 7 8 
*/
