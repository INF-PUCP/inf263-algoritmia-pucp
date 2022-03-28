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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* previous = nullptr;
        TreeNode* current = root;
        bool is_left;
        while (current != nullptr) {
            previous = current;
            if (current->val > val) {
                current = current->left;
                is_left = true;
            } else {
                current = current->right;
                is_left = false;
            }
        }
        if (is_left) {
            previous->left = new TreeNode(val);
        } else {
            previous->right = new TreeNode(val);
        }
        return root;
    }
};
