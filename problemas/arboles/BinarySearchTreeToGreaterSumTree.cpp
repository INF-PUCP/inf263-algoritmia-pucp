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
  vector<int> order;

public:
  void CalculateSum(TreeNode* root, int& sum) {
    if (root == nullptr) return;
    sum += root->val;
    CalculateSum(root->left, sum);
    order.push_back(root->val);
    CalculateSum(root->right, sum);
  }

  void DFS(TreeNode* root, int& sum, int& pos) {
    if (root == nullptr) return;
    CalculateSum(root->left, sum, pos);
    while (pos < order.size() && order[pos] <= root->val) {
      sum -= order[pos];
      pos++;
    }
    root->val += sum;
    CalculateSum(root->right, sum, pos);
  }

  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    CalculateSum(root, sum);
    DFS(root, sum, 0);
    return root;
  }
};
