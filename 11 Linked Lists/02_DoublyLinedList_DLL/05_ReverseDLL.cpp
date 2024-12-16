
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   
    Node* next;     
    Node* back;     
    Node(int data1, Node* next1, Node* back1) {
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

Node* convertArr2DLL(vector<int> arr) {

    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements
//of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 
// Funcion to reverse a doubly linked list
// Stack Brute Force Approach

//Brute 2 pass O(2N)
Node* reverseDLL(Node* head){
    // if head is empty or there is only one element
    // we can directly just return the head
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    stack<int> st;
    Node* temp = head;
  
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    
    return head;

}

//Optimized 1 pass swapping
Node* reverseDLL(Node* head)
{    
   
   if(head==NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* last = NULL;
    while (curr != NULL) 
    {
       last = curr->prev;
       curr->prev = curr->next;
       curr->next = last;

       curr= curr->prev; //Not back as we have chaned the ptrs
    }
    return last->prev;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);
}


