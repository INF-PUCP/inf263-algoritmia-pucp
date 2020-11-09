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
class Solution {
public:
    vector<int> tour;
    
    void DFS(TreeNode* root) {
        if (root == nullptr) return;
        DFS(root->left);
        tour.push_back(root->val);
        DFS(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        tour.clear();
        DFS(root);
        return tour;
    }
};
