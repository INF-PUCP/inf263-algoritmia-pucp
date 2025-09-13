// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> merged_intervals;
        std::sort(intervals.begin(), intervals.end());

        std::vector<int> interval{intervals[0]};
        for (size_t i = 1; i < intervals.size(); i++) {
            if (interval[0] <= intervals[i][0] && intervals[i][0] <= interval[1]) {
                interval[1] = std::max(interval[1], intervals[i][1]);
            } else {
                merged_intervals.push_back(interval);
                interval = intervals[i];
            }
        }
        merged_intervals.push_back(interval);
        return merged_intervals;
    }
};
