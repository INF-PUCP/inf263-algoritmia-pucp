// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min_value = min(p->val, q->val);
        int max_value = max(p->val, q->val);
        
        if (min_value <= root->val && root->val <= max_value) {
            return root;
        }

        if (max_value < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }
};