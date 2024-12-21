// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

 //Brute - Stack TC O(2N 2loops) scO(N) ..external dstruct stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != NULL) {

            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->val != st.top()) {
                return false;
            }
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

//optimal 2 pts
class Solution {
private:
    ListNode* reverseLL(ListNode* head) {
        // base case
        if (head->next == NULL || head == NULL) {
            return head;
        }
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;  //by mistake dont return head
    }

public:
    bool isPalindrome(ListNode* head) {
        // if single or NULL ..its a palindrome
        if (head->next == NULL || head == NULL) {
            return true;
        }

        // step 1 : find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL &&  fast->next->next != NULL) { // stop at 2ndlast for even
            slow = slow->next; // we want to stop slow at first middle
            fast = fast->next->next;
        }
        // step 2: reverse second half
        ListNode* rightHead = reverseLL(slow->next);

        // step 3 : check both half now
        ListNode* first = head;
        ListNode* second = rightHead;
        while (second != NULL) {
            // return false if not palindrome
            if (first->val != second->val) {  //silly dont  compare first!=second
                reverseLL(rightHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(rightHead);
        return true;
    }
};
