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
//Brute
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL || head == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        int n = 0;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        int res = n / 2;
        temp = head;

        while (temp != NULL) {

            res--;
            if (res == 0) {
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                delete middle;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

 //Optimal
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL || head == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        //Get the middle position
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow points middle..so remove slow simply
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;
    }
};
