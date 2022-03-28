// https://leetcode.com/problems/binary-tree-paths/

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
    deque<int> path;
    vector<string> paths;
public:
    string PathToString(void) {
        string str_path = "";
        int nodes = (int) path.size();
        for (int i = 0; i < nodes; i++) {
            if (i > 0) str_path += "->";
            str_path += to_string(path[i]);
        }
        return str_path;
    }

    void DFS(TreeNode* root) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string str_path = PathToString();
            paths.push_back(str_path);
        } else {
            if (root->left != nullptr) DFS(root->left);
            if (root->right != nullptr) DFS(root->right);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        DFS(root);
        return paths;
    }
};