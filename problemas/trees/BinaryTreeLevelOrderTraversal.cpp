// https://leetcode.com/problems/binary-tree-level-order-traversal/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;

        if (root == nullptr) {
            return levels;
        }
        
        queue<pair<TreeNode*, int>> tour;
        tour.push(make_pair(root, 0));

        while (!tour.empty()) {
            TreeNode* node = tour.front().first;
            int height = tour.front().second;            
            tour.pop();

            if (height == levels.size()) {
                levels.push_back({node->val});
            } else {
                levels.back().push_back(node->val);
            }

            if (node->left != nullptr) {
                tour.push(make_pair(node->left, height + 1));
            }

            if (node->right != nullptr) {
                tour.push(make_pair(node->right, height + 1));
            }
        }

        return levels;
    }
};