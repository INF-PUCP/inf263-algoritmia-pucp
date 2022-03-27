// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> arrays = {nums1, nums2};
        for (int i = 0; i < 2; i++) {
            sort(arrays[i].begin(), arrays[i].end());
        }

        vector<int> len;
        for (int i = 0; i < 2; i++) {
            len.push_back((int)arrays[i].size());
        }

        vector<int> intersection;
        int j = 0;
        for (int i = 0; i < len[0]; i++) {
            while (j < len[1] && arrays[1][j] < arrays[0][i])
                j++;
            if (j == len[1])
                break;
            if (arrays[0][i] == arrays[1][j]) {
                intersection.push_back(arrays[1][j]);
                j++;
            }
        }
        return intersection;
    }
};