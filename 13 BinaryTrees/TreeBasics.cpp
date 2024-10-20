
//root->.val does not store any value ..it just is used to access the nodes/values
  
TreeNode* root = new TreeNode();  // root stores the address of a new TreeNode object

root->val = 5;     // Use `->` to access 'val' field of the object via the pointer
(*root).val = 5;   // Equivalent to the above, but using `*root` to access the object first

//Node Structure
struct TreeNode {
    int val;               // Value of the node-val 
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize node
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

------------------------------------------------------------------------------------------------------

// 3. Tree Traversals
// Tree traversal is a way to visit all nodes in a binary tree. There are different ways to traverse:

//In-order Traversal (Left, Root, Right):
void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);          // Visit left subtree
    cout << root->val << " ";     // Visit root
    inOrder(root->right);         // Visit right subtree
}



//Pre-order Traversal (Root, Left, Right):
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";     // Visit root
    preOrder(root->left);         // Visit left subtree
    preOrder(root->right);        // Visit right subtree
}




//Post-order Traversal (Left, Right, Root):
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);        // Visit left subtree
    postOrder(root->right);       // Visit right subtree
    cout << root->val << " ";     // Visit root
}



//Level-order Traversal (Breadth-First Search):
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";  // Visit node
        if (node->left) q.push(node->left);    // Enqueue left child
        if (node->right) q.push(node->right);  // Enqueue right child
    }
}
-----------------------------------------------------------------------------
  /*
TreeNode* root; is a pointer to a TreeNode. It stores the address where the actual TreeNode object is located.
The actual value (val) and the pointers to the left and right children (left, right) are stored inside the TreeNode object itself, which is pointed to by the TreeNode*.
Example:
TreeNode* root = new TreeNode(5);
In this case:
root stores the address of the newly allocated TreeNode object. ...not only the top root but every time new root
To access the value inside the node, you would use root->val, which gives you the value (5 in this case).
*/
