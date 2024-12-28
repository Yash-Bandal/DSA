class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int key) {
        Node* head = *head_ref;
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == key) {
                // 1. check if head
                if (curr == head) {
                    head = head->next;
                }

                // define pointers
                // 2. Node in between
                Node* prevNode = curr->prev;
                Node* nextNode = curr->next;
                // check if existing..there may be single node
                if (nextNode) {
                    nextNode->prev = prevNode;
                }
                if (prevNode) {
                    prevNode->next = nextNode;
                }
                free(curr);
                curr = curr->next;

            } else {
                curr = curr->next;
            }
            *head_ref = head;  //dont forget to reassign value..else gives 0 as head..not nptr
        }
    }
};
