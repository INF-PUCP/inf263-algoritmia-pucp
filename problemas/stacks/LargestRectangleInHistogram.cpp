// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
 private:
  vector<int> GetMaxWidth(vector<int> heights) {
    stack<int> rem;
    int n_heights = (int)heights.size();
    vector<int> max_width(n_heights);
    for (int i = 0; i < n_heights; i++) {
      while (!rem.empty() && heights[rem.top()] > heights[i]) {
        int index = rem.top();
        rem.pop();
        max_width[index] = i - index;
      }
      rem.push(i);
    }
    while (!rem.empty()) {
      int index = rem.top();
      rem.pop();
      max_width[index] = n_heights - index;
    }
    return max_width;
  }

 public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> reverse_heights = heights;
    reverse(reverse_heights.begin(), reverse_heights.end());

    vector<int> max_right_width = GetMaxWidth(heights);
    vector<int> max_left_width = GetMaxWidth(reverse_heights);

    reverse(max_left_width.begin(), max_left_width.end());

    int max_area = 0;
    int n_heights = (int)heights.size();
    for (int i = 0; i < n_heights; i++) {
      int width = max_left_width[i] + max_right_width[i] - 1;
      int area = width * heights[i];
      max_area = max(max_area, area);
    }
    return max_area;
  }
};