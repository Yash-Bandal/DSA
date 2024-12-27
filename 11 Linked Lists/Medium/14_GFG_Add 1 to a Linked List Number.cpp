class Solution {
private:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* newHead = reverse(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    Node* addOne(Node* head) {
        head = reverse(head);
        int carry = 1;
        Node* temp = head;
        while (temp != NULL) {
            int NodeSum = temp->data + carry;
            temp->data = NodeSum; // replace data inside with 1/0 +
            // result either 1 digit if temp->data <9
            // or result is 2 digit 10 if data = 9..thus handle 2 cases
            if (NodeSum <= 9) { // when no. are 1 2 3 4 ...8 9
                carry = 0;
                break;
            } else {         // if NodeSum inside gets 10
                NodeSum = 0; // replace 10 with 0 and carry 1
                carry = 1;
            }
            temp=temp->next;
        }
        // case when last Node may be 9..thus NodeSum = 10 = 1->0-> otherNodes
        if (carry == 1) {
            Node* newHead = new Node(1);
            head = reverse(head);
            newHead->next = head;
            return newHead;
        }
        // else normal..if last nodeSum inside remains <=9
         head = reverse(head);
        return head;
    }
};
