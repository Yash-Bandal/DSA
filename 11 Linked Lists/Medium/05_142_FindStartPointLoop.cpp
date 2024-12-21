/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute O(N Log N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> nodeMp;
        ListNode* LNode = head;
        while(LNode != NULL) {

            if (nodeMp.find(LNode) != nodeMp.end()) {
               return LNode ;
            }
            nodeMp[LNode] = 1;
            LNode = LNode->next;
        }
        return NULL;
    }
};

// Optimal 2 pts
/*
2 steps
In step 1
First ..when loop detected..we have both pointers at collision plave
In step 2
Move slow to head ..and both move pointers by 1 position(even fast) until they
are same again that is move until they collide again the plave of 2nd collision
is the loop start
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL &&
               fast->next != NULL) { // you forget this..dont do temp!=null
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
/*
silly.... wrong
  if (slow == fast) {
      slow = head;
      fast = fast->next;
      slow = slow->next;
       if (slow == fast) {
         return fast;
     }
 }


 Note always move pointers inside while loop..
 just imagine..how will the pointers move inside if condition.silly
*/

