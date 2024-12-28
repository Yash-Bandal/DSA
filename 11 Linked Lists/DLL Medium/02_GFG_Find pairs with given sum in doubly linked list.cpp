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
