//Brute
class Solution {
public:
int countNodesinLoop(Node *head) {
        unordered_map<Node*, int> nodeMp;
        Node* temp = head;
        int timer = 0;
        while(temp != NULL) {

            if (nodeMp.find(temp) != nodeMp.end()) {
                int LoopL= timer-nodeMp[temp];
                return LoopL;
            }
            nodeMp[temp] = timer;
            temp = temp->next;
            timer++;
        }
        return 0;
    }
};

// Optimal 2 pointers
class Solution {
private:
    int findLength(Node* fast, Node* slow) {
        //Move 1 time..as initially both at same position..so move 1 time 
        fast = fast->next;
        int cnt = 1;
        while (slow != fast) {
            //next move until again meet
            fast = fast->next;
            cnt++;
        }
        return cnt;
    }

public:
    int countNodesinLoop(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { //when they meey
                return findLength(fast, slow);
            }
        }

        return 0;
    }
};
