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
private:
  map<TreeNode*, int> dp;

public:
  int maxDownSum(TreeNode* root) {
    if (root == nullptr) return 0;
    if (dp.count(root)) return dp[root];
    int result = max(0, root->val);
    result = max(result, root->val + maxDownSum(root->left));
    result = max(result, root->val + maxDownSum(root->right));
    dp[root] = result;
    return dp[root];
  }

  int maxPathSum(TreeNode* root) {
    if (root == nullptr)
      return INT_MIN;
    int max_sum = root->val;

    if (root->left != nullptr)
      max_sum = max(max_sum, maxPathSum(root->left));
      
    if (root->right != nullptr)
      max_sum = max(max_sum, maxPathSum(root->right));

    max_sum = max(max_sum, maxDownSum(root->left) + root->val + maxDownSum(root->right));
    return max_sum;
  }
};
