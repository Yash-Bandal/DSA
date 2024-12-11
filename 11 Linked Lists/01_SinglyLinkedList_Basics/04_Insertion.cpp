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

Node *InsertHead(Node *head,int val)
{
    Node* temp=new Node(val,head);
    return temp;
}

Node *InsertTail(Node *head,int val)
{ 
    if(head == NULL){  //empty LL
        return new Node(val);
    }
    Node *temp=head;
    while(temp->next !=NULL){   //stop at last element..not like tem!=NUL,L
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;

}
Node*InsertK(Node* head , int val,int k){
    //1. edge case 1-empty LL []..inset at first 
    if(head == NULL){ //if no ele and if k==1 only ..k=7 8 9...not possible
        if(k == 1){
            Node*temp = new Node(val);
            return temp;
        }
    }
    //2. insert head k=1
     if(k == 1){
         Node*temp = new Node(val,head);
         return temp;
     }
     //3.between
     int cnt=0;
     Node*temp = head;
     while(temp != NULL){
        cnt++;
        if(cnt == k-1){ //reach prev postion 
          //1. create
          Node* x = new Node(val);
          //2. connect
          x->next=temp->next;
          //3. reconnect temp
          temp->next=x; 
          break;
            
        }
        temp=temp->next;

     }
  return head;

}

//variety..

Node*InsertEle_Before_Val(Node* head ,int ele, int val){
    //1. edge case 1-empty LL []..inset at first 
    if(head == NULL){ 
       return NULL;
    }
    //2. insert before head 
     if(head->data == val){
         Node*temp = new Node(val,head);
         return temp;
     }
     //3.between
     int cnt=0;
     Node*temp = head;
     while(temp->next != NULL){  //no need to reach end
        if(temp->next->data == val){ //reach prev postion 
          //1. create
          Node* x = new Node(ele);
          //2. connect
          x->next=temp->next;
          //3. reconnect temp
          temp->next=x; 
          break;
            
        }
        temp=temp->next;

     }
  return head;

}



int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = makeLL(arr);
    cout << "=================== HEAD INSERTION ====================" << endl;
    cout << "Head insert" << endl;

    cout << "\nBefore Head Insert :" << endl;
    printLL(head);

    head = InsertHead(head,0);
    //or
    head= new Node(-1,head);  //O(1) TC 

    cout << "\nAfter Head insert : " << endl;
    printLL(head);

    cout << "=================== TAIL INSERTION ====================" << endl;
    cout << " insert" << endl;

    cout << "\nBefore Tail Insert :" << endl;
    printLL(head);

    head = InsertTail(head,7);

    cout << "\nAfter Tail insert : " << endl;
    printLL(head);

    cout << "=================== K INSERTION ====================" << endl;
    cout << " insert" << endl;

    cout << "\nBefore kth Insert :" << endl;
    printLL(head);
    int k=5;
    if(k > LengthOfLL(head)){
        cout<<"Exceeds.."<<endl;
    }
    else{
        head = InsertK(head,10,k);
        cout << "\nAfter kth insert : " << endl;
        printLL(head);
    }

    cout << "=================== INSERTION BEFORE VALUE ====================" << endl;  //val always present condition
    cout << " insert" << endl;

    cout << "\nBefore Val Insert :" << endl;
    printLL(head);

    head = InsertEle_Before_Val(head,25,10);

    cout << "\nAfter Val insert : " << endl;
    printLL(head);





    return 0;
}

/*
Output :

=================== HEAD INSERTION ====================
Head insert

Before Head Insert :
1 2 3 4 5 6 
After Head insert : 
-1 0 1 2 3 4 5 6 =================== TAIL INSERTION ====================
 insert

Before Tail Insert :
-1 0 1 2 3 4 5 6 
After Tail insert : 
-1 0 1 2 3 4 5 6 7 =================== K INSERTION ====================
 insert

Before kth Insert :
-1 0 1 2 3 4 5 6 7 
After kth insert : 
-1 0 1 2 10 3 4 5 6 7 =================== INSERTION BEFORE VALUE ====================
 insert

Before Val Insert :
-1 0 1 2 10 3 4 5 6 7 
After Val insert : 
-1 0 1 2 25 10 3 4 5 6 7 

*/
