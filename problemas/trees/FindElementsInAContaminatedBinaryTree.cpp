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
class FindElements {
private:
  set<int> on_tree;
public:

  void DFS(TreeNode* root, int val) {
    if (root == nullptr) return;
    root->val = val;
    on_tree.insert(val);
    DFS(root->left, 2 * val + 1);
    DFS(root->right, 2 * val + 2);
  }

  FindElements(TreeNode* root) {
    DFS(root, 0);
  }
  
  bool find(int target) {
    if (on_tree.count(target) > 0) return true;
    return false;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
