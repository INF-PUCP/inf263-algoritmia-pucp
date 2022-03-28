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
typedef long long Long;
const Long INF = LLONG_MAX;

class Solution {
public:
    
    Long Max(TreeNode* root) {
        Long ans = -INF;
        if (root == nullptr) return ans;
        ans = max(ans, (Long) root->val);
        ans = max(ans, Max(root->left));
        ans = max(ans, Max(root->right));
        return ans;
    }
    
    Long Min(TreeNode* root) {
        Long ans = INF;
        if (root == nullptr) return ans;
        ans = min(ans, (Long) root->val);
        ans = min(ans, Min(root->left));
        ans = min(ans, Min(root->right));
        return ans;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (isValidBST(root->left) && isValidBST(root->right) &&
            Max(root->left) < root->val && Min(root->right) > root->val)
            return true;
        return false;
    }
};
