// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    typedef vector<int> Interval;

    bool Overlap(const Interval &a, const Interval &b) {
        return a[1] >= b[0] && a[0] <= b[1];
    }

    Interval Merge(const Interval &a, const Interval &b) {
        Interval merged_interval = {min(a[0], b[0]), max(a[1], b[1])};
        return merged_interval;
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int n_intervals = (int)intervals.size();
        vector<Interval> merged_intervals;
        Interval merged_interval = intervals[0];
        for (int i = 1; i < n_intervals; i++) {
            if (Overlap(merged_interval, intervals[i])) {
                merged_interval = Merge(merged_interval, intervals[i]);
            }
            else {
                merged_intervals.push_back(merged_interval);
                merged_interval = intervals[i];
            }
        }
        merged_intervals.push_back(merged_interval);
        return merged_intervals;
    }
};