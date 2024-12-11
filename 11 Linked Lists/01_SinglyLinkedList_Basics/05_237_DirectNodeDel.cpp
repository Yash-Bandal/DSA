void deleteNodeDirect( Node* ele)  //dont use head ..so no traverse..
{  
    // Condition no edge cases
    // we cant directly delete the noed as we dont have access to prev and traversal
    //thus copy the next node data o the current node to be deleted and delete the nextNode
    Node* nextNode = ele->next;  //1. store next node in temporary node
    ele->data=nextNode->data;    //2. copy next node data 
    ele->next=nextNode->next;    //3. point elem->next->next;
    delete nextNode;

    /*
                original      1-> 2-> 3->4->5  Node ele=2
    1. store newNode = 3
    2. copy 3 to 2 ..ie ele   1-> 3 -> 3 ->4 ->5  
    3.point next              1-> 3-->4->5  ele=2
    delete space allocatedd for the nextNode
    */

}
//-=======================================================================
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node -> next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete nextNode;
    }
};
