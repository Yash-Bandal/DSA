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
class Solution {
private:
    int findLength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int LLsize = findLength(head);
        int mid = (LLsize / 2) +1;
        ListNode* midN = head;
        while (mid != 1) {
            mid--;
            midN = midN->next;
        }
        return midN;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // If the list is empty or has only
        // one element, return the head as
        // it's the middle.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        int count = 0;

        // Count the number of ListNodes in the linked list.
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2 + 1;
        temp = head;

        // Traverse to the middle ListNode by moving
        // temp to the middle position.
        while (temp != NULL) {
            mid = mid - 1;

            // Check if the middle
            // position is reached.
            if (mid == 0) {
                break;
            }
            // Move temp ahead
            temp = temp->next;
        }

        return temp;
    }
};
