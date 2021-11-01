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
  map<TreeNode*, int> height;
public:

  int BFS(TreeNode* root) {
    int maximum_height = 0;
    height[root] = 0;
    queue<TreeNode*> tour;
    tour.push(root);
    while (!tour.empty()) {
      TreeNode* from = tour.front();
      tour.pop();
      TreeNode* to = from->left;
      if (to != nullptr) {
        height[to] = height[from] + 1;
        maximum_height = max(maximum_height, height[to]);
        tour.push(to);
      }
      to = from->right;
      if (to != nullptr) {
        height[to] = height[from] + 1;
        maximum_height = max(maximum_height, height[to]);
        tour.push(to);
      }
    }
    return maximum_height;
  }

  void DFS(TreeNode* root, int maximum_height, int& sum) {
    if (root == nullptr) return;
    int current_height = height[root];
    if (current_height == maximum_height) sum += root->val;
    DFS(root->left, maximum_height, sum);
    DFS(root->right, maximum_height, sum);
  }

  int deepestLeavesSum(TreeNode* root) {
    int maximum_height = BFS(root);
    int sum = 0;
    DFS(root, maximum_height, sum);
    return sum;
  }
};
