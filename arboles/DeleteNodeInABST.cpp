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
  bool IsHere(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    if (key < root->val) return IsHere(root->left, key);
    return IsHere(root->right, key);
  }
  
  int FindMinimum(TreeNode* root) {
    if (root->left == nullptr) return root->val;
    return FindMinimum(root->left);
  }
  
  TreeNode* DeleteNode(TreeNode** root, int key) {
    if (*root == nullptr) return nullptr;
    if (key < (*root)->val) {
      DeleteNode(&((*root)->left), key);
      return (*root);
    }
    if (key > (*root)->val) {
      DeleteNode(&((*root)->right), key);
      return (*root);
    }
    if ((*root)->left == nullptr && (*root)->right == nullptr) {
      *root = nullptr;
      return nullptr;
    }
    if ((*root)->left == nullptr) {
      *root = (*root)->right;
      return *root;
    }
    if ((*root)->right == nullptr) {
      *root = (*root)->left;
      return *root;
    }
    int minimum = FindMinimum((*root)->right);
    (*root)->val = minimum;
    DeleteNode(&((*root)->right), minimum);
    return *root;
  }
  
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!IsHere(root, key)) return root;
    return DeleteNode(&root, key);
  }
};
