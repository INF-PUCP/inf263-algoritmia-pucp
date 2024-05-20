// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, vector<int>> indices;

        int numbersLength = (int)numbers.size();

        for (int i = 0; i < numbersLength; i++) {
            if (indices.count(numbers[i]) == 0) {
                indices[numbers[i]] = {i};
            } else {
                indices[numbers[i]].push_back(i);
            }
        }

        vector<int> solution;

        for (int i = 0; i < numbersLength; i++) {
            int remaining = target - numbers[i];

            if (remaining == numbers[i]) {
                if (indices[remaining].size() > 1) {
                    solution = {indices[remaining][0], indices[remaining][1]};
                    break;
                }
            } else {
                if (indices.count(remaining) > 0) {
                    solution = {indices[numbers[i]][0], indices[remaining][0]};
                    break;
                }
            }
        }

        return solution;
    }
};