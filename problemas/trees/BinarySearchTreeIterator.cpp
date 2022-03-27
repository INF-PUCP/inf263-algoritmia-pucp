/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void LeftInOrder(TreeNode* root) {
        TreeNode* current = root;
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        LeftInOrder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != nullptr) LeftInOrder(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
