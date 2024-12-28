/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while (t1 != NULL ||t2 != NULL) { // we use or bcoz of uneven length of LLs..any one
                             // can exhaust first..so other must continue
            int sum = carry;
            if (t1 != NULL) {
                sum += t1->val;
            }

            if (t2 != NULL) {
                sum += t2->val;
            }

            ListNode* newNode = new ListNode(sum % 10); // not sum..as we want single digit node
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;
            if (t1 != NULL) {
                t1 = t1->next;
            }

            if (t2 != NULL) {
                t2 = t2->next;
            }
        }

        // final
        if (carry) { // if carry has anything add it to new node
            ListNode* newNode = new ListNode(carry);
            // curr = curr->next; //silly  This does nothing because `curr->next` is null here
            curr->next = newNode;
        }
        return dummyNode->next;  //as we dont want -1..we want from next 
    }
};
