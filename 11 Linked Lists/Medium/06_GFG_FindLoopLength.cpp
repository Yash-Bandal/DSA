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
