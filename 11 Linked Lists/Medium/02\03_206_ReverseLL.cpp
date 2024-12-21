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
// Brute - Stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        stack<int> st;
        ListNode* temp = head;
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Brute - Iterative .pointer..see visulization in notebook
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = last;

            last = temp;
            temp = front;
        }
        return last;
    }
};

// Optimized-recursive
class Solution {
private:
    ListNode* reverse(ListNode* head) {

        // Base case return when single node left or empty
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // run case
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = reverse(head);
        return newHead;
    }
};
