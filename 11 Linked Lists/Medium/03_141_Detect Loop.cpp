/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> nodeMp;
        ListNode* temp = head;
        while(temp != NULL) {
//Check if the node exists in the map (
            if (nodeMp.find(temp) != nodeMp.end()) {
                return true;
            }
            nodeMp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};

/*
dbt 1 :We are checking if a node object (with the same memory address) has
already been visited. If the same node pointer appears again, it means there's a
cycle.

dbt 2 :
why not run infinite loop ?
when cycle detected
If the same node is revisited (nodeMp.find(temp) != nodeMp.end()), we return
true, so the loop terminates early.

If there is no cycle, the next pointer of the last node in the list will
eventually be NULL. When temp becomes NULL, the condition while(temp != NULL)
evaluates to false, and the loop exits.
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> nodeMp;

        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare != NULL && hare->next != NULL) {   //you forget this..dont do temp!=null
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return true;
            }
        }
        return false;
    }
};

/*
after d number of steps both meet
d = dist between  the 2 pointers
*/
