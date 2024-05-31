// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root, long long inf, long long sup) {
        if (root == nullptr) {
            return true;
        }

        if (inf >= root->val || root->val >= sup) {
            return false;
        }

        return isValidBST(root->left, inf, root->val) &&
        isValidBST(root->right, root->val, sup);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};