//TC = O(#N) SC O(!)
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


//Optimied - Backtrack
class Solution {
private:
    int getCarryAddedLL(Node* temp) {
        if (temp == NULL) {
            return 1; // Base case: Add 1 when reaching the end of the list
        }

        // Recursive call to process the next node
        int carry = getCarryAddedLL(temp->next);

        // Add carry to the current node's data
        int NodeSum = temp->data + carry;
        if(NodeSum <=9){
            temp->data=NodeSum;
            return 0;
        }
        temp->data=0;
        return 1;
    }

public:
    Node* addOne(Node* head) {
        // Get the carry after adding 1
        int carry = getCarryAddedLL(head);

        // If there's a carry left, create a new node at the front
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        // Otherwise, return the updated head
        return head;
    }
};
