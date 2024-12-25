// // /**
// //  * Definition for singly-linked list.
// //  * struct ListNode {
// //  *     int val;
// //  *     ListNode *next;
// //  *     ListNode() : val(0), next(nullptr) {}
// //  *     ListNode(int x) : val(x), next(nullptr) {}
// //  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// //  * };
// //  */

//Brute 1 :Reverse and Delete from reversed
class Solution {
private:
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dont use defaul head edge case condition single or empty LL..use
        // k==1..

        int cnt = 0;

        head = reverseLL(head);
        if (n == 1) { // headd delete
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return reverseLL(head); // dont forget to return reversed
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            cnt++;
            if (cnt == n) {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        head = reverseLL(head);
        return head;
    }
};


//Brute 2
class Solution {
private:
    int LengthOfLL(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int LengthLL = LengthOfLL(head);
        int res = LengthLL - n; // 0-based index of the node to be removed

        // Special case: Remove the head
        if (res == 0) { // if we get cnt=5 and n=5..thus from back we are
        deleting head
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        // Get pointer to res position from front
        while (res != 1) { // not 0..as 1 is head
            temp = temp->next;
            res--;
        }

        // Remove the nth node
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};

// Optimal 2ptrs
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;
        // Move fast ptr N steps
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) { // ie if fast points to end..and has crossed last ele..that
                    // is if N big than count or equal to count
            return head->next;
        }
        while (fast->next !=
               NULL) { // dont confuz..we have to reach last node not NULL
            slow = slow->next;
            fast = fast->next;
        }

        // slow points to prev node to be deleted
        ListNode* NodeToDel = slow->next;
        slow->next = slow->next->next;
        delete NodeToDel;
        return head;
    }
};
