//Brute -TLE
//TLE O(N^2)..not exactly but n^2..almost
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> res;
        Node* temp1 = head;

        while (temp1 != NULL) {
            Node* temp2 = temp1->next;
            while (temp2 != NULL) {
                if (temp1->data + temp2->data == target) {
                    res.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next; // Move temp2 to the next node
            }
            temp1 = temp1->next; // Move temp1 to the next node
        }
        return res;
    }
};

//===============================================================================================

//Optimized
class Solution {
private:
    Node* getTail(Node* head) {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }

public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
        vector<pair<int, int>> res;
        Node* left = head;
        Node* right = getTail(head);
        // as sorted given..thus only check until they vross each other
        while (left->data < right->data) {
            if (left->data + right->data == target) {
                res.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if (left->data + right->data <
                       target) { // if sum is less..increase left
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return res;
    }
};
