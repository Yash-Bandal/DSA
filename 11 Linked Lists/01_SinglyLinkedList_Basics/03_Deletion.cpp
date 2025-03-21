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
    // Constructor for single node
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

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

Node *makeLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // we declare head every time
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;

    free(temp); // or delete temp; dpnt do delete head by mistake..as its pointing to next

    return head;
}

Node *deleteTail(Node *head)
{
    // 1. Handle Empty O Single node..(dont del single node)
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    // 2. Traverse to Second last
    Node *temp = head;
    while (temp->next->next != NULL)
    { //!=   ..stop when 2nd last found
        temp = temp->next;
    }
    // 3. Free Last and make 2nd last tail
    free(temp->next); // del tail
    temp->next = nullptr;

    return head;
}

Node *deleteK(Node *head, int k)
{
    // 1. Handle Empty Or Single node..(dont del single node)
    if (k == 1)
    { // headd delete
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // 2. k btw or tail
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next; // update previos pointer first
            free(temp);                    // temp is denoting the node to be deleted..it has reached there
            break;
        }
        prev = temp;
        temp = temp->next; // like swapping or min max..prev is taking place of temp moving forward
    }
    return head;
}

Node *deleteEle(Node *head, int ele)
{
    // 1. Handle Empty Or Single node..(dont del single node)
    if (head->data == ele)
    { // headd data delete
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // 2.ele btw or tail  no need of position

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == ele) // check data instead of tracking pos
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
void deleteNodeDirect( Node* ele)  //dont use head ..so no traverse..
{  
    // Condition no edge cases
    // we cant directly delete the noed as we dont have access to prev and traversal
    //thus copy the next node data o the current node to be deleted and delete the nextNode
    Node* nextNode = ele->next;  //1. store next node in temporary node
    ele->data=nextNode->data;    //2. copy next node data 
    ele->next=nextNode->next;    //3. point elem->next->next;
    delete nextNode;

    /*
    1-> 2-> 3->4->5  ele=2
    1. store newNode = 3
    2. copy 3 to 2 ..ie ele  1-> 3 -> 3 ->4 ->5  
    3.point next              1-> 3-->4->5  ele=2
    delete space allocatedd for the nextNode
    */

}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6,7,8,9,10};
    Node *head = makeLL(arr);

    cout << "=================== HEAD DELETION ====================" << endl;
    cout << "Head Deletion" << endl;

    cout << "\nBefore Delete Head :" << endl;
    printLL(head);

    head = deleteHead(head);

    cout << "\nAfter Delete Head : " << endl;
    printLL(head);

    cout << endl;


    cout << "=================== TAIL DELETION ====================" << endl;
    cout << "Tail Deletion" << endl;

    cout << "\nBefore Delete Tail :" << endl;
    printLL(head);

    head = deleteTail(head);

    cout << "\nAfter Delete Tail : " << endl;
    printLL(head);

    cout << endl;


    cout << "=================== K DELETION ====================" << endl;
    cout << "K Deletion" << endl;
    int k = 3;
    if (k > LengthOfLL(head))
    {
        cout << "K exceedss......" << endl;
    }
    else
    {
        cout << "\nBefore " << k << "rd position Deletion :" << endl;
        printLL(head);
        head = deleteK(head, k);
        cout << "\n After " << k << "rd position Deletion :" << endl;
        printLL(head);
    }

    cout << endl;


    cout << "=================== ELEMENT DELETION ====================" << endl;
    cout << "Element Deletion" << endl;
    
    int ele = 9;
    if (checkEle(head, ele) == 0)
    {
        cout << "element Absent......" << endl;
    }
    else
    {
        cout << "\nBefore " << ele << " Deletion :" << endl;
        printLL(head);
        head = deleteEle(head, ele);
        cout << "\n After " << ele << " Deletion :" << endl;
        printLL(head);
    }

    cout << endl;
    cout << "=================== DIRECT NODE DELETION ====================" << endl;
    cout << "Direct Deletion" << endl;

    cout << "\nBefore Delete Node directly :" << endl;
    printLL(head);

    Node* nodeToDel= head->next->next;
    deleteNodeDirect(nodeToDel);

    cout << "\nAfter Delete Node Directly : " << endl;
    printLL(head);

    cout << endl;

    return 0;
}

/*
Output :
=================== HEAD DELETION ====================
Head Deletion

Before Delete Head :
1 2 3 4 5 6 7 8 9 10 
After Delete Head : 
2 3 4 5 6 7 8 9 10 
=================== TAIL DELETION ====================
Tail Deletion

Before Delete Tail :
2 3 4 5 6 7 8 9 10 
After Delete Tail : 
2 3 4 5 6 7 8 9 
=================== K DELETION ====================
K Deletion

Before 3rd position Deletion :
2 3 4 5 6 7 8 9 
 After 3rd position Deletion :
2 3 5 6 7 8 9 
=================== ELEMENT DELETION ====================
Element Deletion

Before 9 Deletion :
2 3 5 6 7 8 9 
 After 9 Deletion :
2 3 5 6 7 8 
=================== DIRECT NODE DELETION ====================
Direct Deletion

Before Delete Node directly :
2 3 5 6 7 8 
After Delete Node Directly : 
2 3 6 7 8 

*/
