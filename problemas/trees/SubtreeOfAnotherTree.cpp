// https://leetcode.com/problems/subtree-of-another-tree/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool sameTree(TreeNode* r, TreeNode* s) {
        if (r == nullptr && s == nullptr) {
            return true;
        }

        if (r == nullptr || s == nullptr) {
            return false;
        }

        if (r->val != s->val) {
            return false;
        }

        return sameTree(r->left, s->left) && sameTree(r->right, s->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return sameTree(root, subRoot) ||
        root->left != nullptr && isSubtree(root->left, subRoot) ||
        root->right != nullptr && isSubtree(root->right, subRoot);
    }
};