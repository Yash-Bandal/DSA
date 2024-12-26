/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Brute O(M * N)
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        ListNode* temp1 = head1;
        while (temp1 != NULL) {
            ListNode* temp2 = head2;
            while (temp2 != NULL) {
                if (temp1 == temp2) {  //we compare nodes not data..thus position matching required here
                    return temp1;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return NULL;
    }
};


//===============================================================================


//Little optimized O(M+N) MAPS
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head1;
        while (temp != NULL) {
            mpp[temp] = 1;
            temp = temp->next;
        }
        while (head2 != NULL) {
            if(mpp.find(head2) != mpp.end()){
                return head2;
            }
            head2 = head2->next;
        }
        return NULL;
    }
};



//===============================================================================

//SET
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        unordered_set<ListNode*> st;
        ListNode* temp = head1;
        while (temp != NULL) {
            st.insert(temp);
            temp = temp->next;
        }
        while (head2 != NULL) {
            if(st.find(head2) != st.end()){
                return head2;
            }
            head2 = head2->next;
        }
        return NULL;
    }
};



//===============================================================================


//All above use High Sc..thus optmize it
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) // will actually never be true..as t1 == t2 inside will
                         // take care of END
        // if no collision both meet at nptr..thus t1=t2=nptr
        {
            t1 = t1->next;
            t2 = t2->next;
            if (t1 == t2) {
                return t1; // if no collision npptr returned at last
            }
            if (t1 == NULL) {
                t1 = headB;
            }

            if (t2 == NULL) {
                t2 = headA;
            }
        }
        return t1;
    }
};


//===============================================================================


//Distance optimal
class Solution {
private:
    ListNode* collisionPt(ListNode* sh, ListNode* lh, int dist) {
        // Advance the larger list by 'dist' nodes
        while (dist > 0) {
            lh = lh->next;
            dist--;
        }
        // Move both pointers until they meet at the intersection point
        while (sh != lh) {
            sh = sh->next;
            lh = lh->next;
        }
        return sh; // Return the intersection node (or NULL if no intersection)
    }

public:
    ListNode* getIntersectionNode(ListNode* head1, ListNode* head2) {
        if (!head1 || !head2) return NULL; // Handle edge cases

        // Step 1: Calculate lengths of both linked lists
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        int N1 = 0, N2 = 0;

        while (t1) {
            N1++;
            t1 = t1->next;
        }

        while (t2) {
            N2++;
            t2 = t2->next;
        }

        // Step 2: Align both lists by their lengths
        if (N1 < N2) {
            return collisionPt(head1, head2, N2 - N1);
        } else {
            return collisionPt(head2, head1, N1 - N2);
        }
    }
};
