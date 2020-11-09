class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    if (n == 0) return intervals;
    vector<vector<int>> result;
    vector<int> current = intervals[0];
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] <= current[1]) {
        current[1] = max(current[1], intervals[i][1]);
      } else {
        result.push_back(current);
        current = intervals[i];
      }
    }
      result.push_back(current);
    return result;
  }
};
