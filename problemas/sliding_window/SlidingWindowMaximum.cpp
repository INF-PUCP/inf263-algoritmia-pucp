// https://leetcode.com/problems/sliding-window-maximum/
struct MinMaxStack {
  stack<int> st, mn, mx;
  void Push(int x) {
    if (st.empty()) {
      mn.push(x);
      mx.push(x);
    } else {
      mn.push(min(x, mn.top()));
      mx.push(max(x, mx.top()));
    }
    st.push(x);
  }
  void Pop(void) {
    st.pop();
    mn.pop();
    mx.pop();
  }
  int Top(void) {
    return st.top();
  }
  int GetMin(void) {
    return mn.top();
  }
  int GetMax(void) {
    return mx.top();
  }
  bool IsEmpty(void) {
    return st.empty();
  }
};
struct MinMaxQueue {
  MinMaxStack front, back;
  void Push(int x) {
    back.Push(x);
  }
  void Pop(void) {
    if (front.IsEmpty()) {
      while (!back.IsEmpty()) {
        int last = back.Top();
        back.Pop();
        front.Push(last);
      }
    }
    front.Pop();
  }
  int GetMin(void) {
    int mn = INT_MAX;
    if (!front.IsEmpty()) mn = min(mn, front.GetMin());
    if (!back.IsEmpty()) mn = min(mn, back.GetMin());
    return mn;
  }
  int GetMax(void) {
    int mx = INT_MIN;
    if (!front.IsEmpty()) mx = max(mx, front.GetMax());
    if (!back.IsEmpty()) mx = max(mx, back.GetMax());
    return mx;
  }
};
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MinMaxQueue q;
    vector<int> mxs;
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
      q.Push(nums[i]);
      if (i >= k) q.Pop();
      if (i >= k - 1) mxs.push_back(q.GetMax());
    }
    return mxs;
  }
};