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


Node *convertArrToLL(vector<int> &arr) // Like vector func..int void..Node* datatyoe func
{
    Node *head = new Node(arr[0]); // we declare head every time
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;  // mover pointing to next node
        mover = mover->next; // moving mover to next node
        // mover=temp; //or above line..any
    }
    return head;
}

//Traverse
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    { // or != NULL or just while(temp)
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//Length
int LengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
//Check
int checkEle(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {12, 5, 6, 4};

    /*
       Call the conversion function to get the linked list head.
       The linked list will look like this:
       12 -> 5 -> 6 -> 4 -> NULL
    */
    Node *head = convertArrToLL(arr);
    cout << head->data << endl; // 12

    // Traverse
    cout << "The LL is :" << endl;
    traverse(head);

    // Length of LL
    cout << "\nThe Length of LL  is :" << LengthOfLL(head) << endl;

    // Element Seach
    int ele;
    cout << "Enter element to check" << endl;
    cin >> ele;
    if (checkEle(head, ele) == 1){
        cout << ele << " exists" << endl;
    }else{
        cout << "Not exixsts" << endl;
    }

    return 0;
}

/*
   Visualization: convertfunc

   Input Array: {12, 5, 6, 4}
   Linked List Construction:
   Step 1: Create head -> Node(12)
   Step 2: Add Node(5), link to head -> 12 -> 5
   Step 3: Add Node(6), link to previous -> 12 -> 5 -> 6
   Step 4: Add Node(4), link to previous -> 12 -> 5 -> 6 -> 4
   Final Linked List: 12 -> 5 -> 6 -> 4 -> NULL

===================================================================

Output :
12
The LL is :
12 5 6 4
The Length of LL  is :4

====================================================================

    // Create a linked list without the func
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

====================================================================

*/
