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
 //Brute force- Array
class Solution {
private:
    ListNode* convertArrLL(vector<int>& arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = mover->next;
        }
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {

//this is imp or gives runtime err if NULl LL not handled
        if (head == NULL || head->next == NULL) {
            return head;
        }
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());
        return convertArrLL(arr);
    }
};

//Optimal - Merge sort
class Solution {
private:
    ListNode* getmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // to mark to 1st middle..not 2nd middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1); // will be used as head later
        ListNode* temp = dummyNode;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {  //for descending order..just change < to >
                temp->next = list1;
                temp = temp->next; // or temp = list1..same both..moving temp ahead
                list1 = list1->next;
            } else {

                temp->next = list2;
                temp = temp->next; // or temp = list1..same both..moving temp ahead
                list2 = list2->next;
            }

            // any elems remaining in single
            if (list1 != NULL) {
                temp->next = list1;
            } else {
                temp->next = list2;
            }
        }
        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = getmiddle(head);
        //get left and right
        ListNode* left = head;
        ListNode* right = middle->next;
        //then break the list from middle
        middle->next = nullptr;

        //recurseion mergesort
        left = sortList(left);
        right= sortList(right);
        return mergeLL(left,right);

    }
};
