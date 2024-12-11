
#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToLL(vector<int> &arr) {
    if(arr.size() == 1){
        return new Node(arr[0]); // // auto assing 2 nptrs..
    } else {
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++) {
            Node *temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = prev->next;
        }
        return head;
    }
}

void printLL(Node *tail) {
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->next;
    }
}

Node* InsertHead(Node *head, int val) {
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node *InsertBeforeTail(Node *head, int val)
{
    // Handle empty list
    if (head == nullptr) {
        return new Node(val);
    }

    // Handle single element list (head == tail)
    if (head->next == nullptr) {
        Node *newNode = new Node(val, head, nullptr);
        head->back = newNode; // Link the original head's back pointer
        return newNode;       // New node becomes the head
    }

    // General case
    Node *tail = head;
    while (tail->next != nullptr) { // Traverse to the tail
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* InsertBeforeK(Node *head, int val, int k) {
    //handle empty
    if (head == nullptr && k == 1) {
        return new Node(val);
    }
        // Handle single element list (head == tail)
    if (k == 1) {
        Node *newNode = new Node(val, head, nullptr);
        head->back = newNode;
        return newNode;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void InsertEle_Before_Node(Node* &head, Node* temp, int val) {
    if (temp == head) {
        Node* newNode = new Node(val, temp, nullptr);
        head = newNode;
        temp->back = newNode;
        return;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> single = {1};

    Node *head = convertArrToLL(arr);
    Node *head2 = convertArrToLL(single);

    cout << "=================== HEAD INSERTION ====================" << endl;
    cout << "Head insert" << endl;

    cout << "\nBefore Head Insert :" << endl;
    printLL(head);

    head = InsertHead(head, 0);
    cout << "\nAfter Head insert : " << endl;
    printLL(head);
    cout << "\n=================== TAIL INSERTION ====================" << endl;
    cout << " insert" << endl;

    cout << "\n Before Ele inserted before Tail :" << endl;
    printLL(head);
    cout<<"\nSingle"<<endl;
    printLL(head2);

    head = InsertBeforeTail(head, 100);
    head2 = InsertBeforeTail(head2, 200);

    cout << "\nAfter Ele inserted before Tail : " << endl;
    printLL(head);
    cout<<endl;
    printLL(head2);

    cout << "\n=================== K INSERTION ====================" << endl;
    cout << " insert" << endl;

    cout << "\nBefore kth Insert :" << endl;
    printLL(head);
    int k = 4;
    head = InsertBeforeK(head, 10, k);
    cout << "\nAfter kth insert : " << endl;
    printLL(head);

    cout << "\n=================== INSERTION BEFORE NODE ====================" << endl;
    cout << " insert" << endl;

    cout << "\nBefore Val Insert :" << endl;
    printLL(head);

    Node* temp = head->next;
    InsertEle_Before_Node(head, temp, 25);

    cout << "\nAfter Val insert : " << endl;
    printLL(head);

    return 0;
}
