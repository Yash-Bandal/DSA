//Brute Force using count
class Solution {
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0)
                c0++;
            else if (temp->data == 1)
                c1++;
            else
                c2++;

            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (c0) {
                temp->data = 0;
                Q c0--;
            } else if (c1) {
                temp->data = 1;
                c1--;
            } else {
                temp->data = 2;
                c2--;
            }
            temp = temp->next;
        }

        return head;
    }
};
