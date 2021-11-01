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
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int cnt = 0;
    queue<TreeNode*> tour;
    tour.push_back(root);
    while (!tour.empty()) {
      cnt++;
      TreeNode* from = tour.front();
      tour.pop();
      if (from->left != nullptr) tour.push_back(from->left);
      if (from->right != nullptr) tour.push_back(from->right);
    }
    return cnt;
  }
};
