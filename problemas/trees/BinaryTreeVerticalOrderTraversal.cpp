// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

class Solution {
private:
    typedef pair<TreeNode*, int> Pair;

    const int MAX_VAL = 100;

    void BFS(TreeNode* root, vector<vector<int>>& columns) {
        if (root == nullptr) return;
        queue<Pair> tour;
        tour.push({root, 0});
        while (!tour.empty()) {
            Pair head = tour.front();
            tour.pop();
            TreeNode* node = head.first;
            int column = head.second;
            columns[column + MAX_VAL - 1].push_back(node->val);
            if (node->left != nullptr) {
                tour.push({node->left, column - 1});
            }
            if (node->right != nullptr) {
                tour.push({node->right, column + 1});
            }
        }
    }

    vector<vector<int>> GetVerticalOrderTraversal(const vector<vector<int>>& columns) {
        vector<vector<int>> vertical_order_traversal;
        for (int i = 0; i < 2 * MAX_VAL + 1; i++) {
            if (columns[i].size() > 0) {
                vertical_order_traversal.push_back(columns[i]);
            }
        }
        return vertical_order_traversal;
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> columns(2 * MAX_VAL + 1);
        BFS(root, columns);
        vector<vector<int>> vertical_order_traversal = GetVerticalOrderTraversal(columns);
        return vertical_order_traversal;
    }
};

// Remark: The problem is from the premium platform.
// I don't pay for premium, so I created my own testing to verify that.

// int main(void) {
//     Solution solution;
//     TreeNode nodes[7];
//     nodes[0] = TreeNode(4, nullptr, nullptr);
//     nodes[1] = TreeNode(0, nullptr, nullptr);
//     nodes[2] = TreeNode(1, nullptr, nullptr);
//     nodes[3] = TreeNode(7, nullptr, nullptr);
//     nodes[4] = TreeNode(9, &nodes[0], &nodes[1]);
//     nodes[5] = TreeNode(8, &nodes[2], &nodes[3]);
//     nodes[6] = TreeNode(3, &nodes[4], &nodes[5]);
//     vector<vector<int>> order = solution.verticalOrder(&nodes[6]);
//     for (int i = 0; i < (int) order.size(); i++) {
//         for (int j = 0; j < (int) order[i].size(); j++) {
//             cout << order[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }