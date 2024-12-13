Node * insertAtTail(Node *head, int val) {
    // Handle empty list
    if (head == nullptr) {
        return new Node(val);
    }

    // Handle single element list (head == tail)
    if (head->next == nullptr) {
        Node *newNode = new Node(val, head, nullptr);
        head->prev = newNode; // Link the original head's back pointer
        return newNode;       // New node becomes the head
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail=tail->next;
    }

    Node* newTail = new Node(val,nullptr,tail);
    tail->next = newTail;
    return head;
}
