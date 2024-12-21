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

//Brute O2n and ON SC
class Solution {
private:
    ListNode* convertArrLL(const vector<int>& arr) {
        if (arr.empty())
            return NULL; // Edge
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int> oddNums;
        vector<int> evenNums;
        ListNode* temp = head;
        int index = 1;
        while (temp != NULL) {
            if (index % 2 == 1) {
                oddNums.push_back(temp->val);
            } else {
                evenNums.push_back(temp->val);
            }
            index++;
            temp = temp->next;
        }
        // combine
        for (auto it : evenNums) {
            oddNums.push_back(it);
        }
        return convertArrLL(oddNums);
    }
};

//optimal 1 pass
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // handle edge case..dont forget
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // save for further joining of odd tail

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next; // Link odd node to the next odd node
            even->next =
                even->next->next; // Link even node to the next even node

            odd = odd->next;   // Move odd pointer to the next odd node
            even = even->next; // Move even pointer to the next even node
        }
        // reconnect tail of odd to even part
        odd->next = evenHead;
        return head;
    }
};
