// https://leetcode.com/problems/min-stack/
class MinStack {
 private:
  stack<int> st, mn;
 public:
  MinStack() {
  }

  void push(int val) {
    if (st.empty()) {
      mn.push(val);
    } else {
      mn.push(min(mn.top(), val));
    }
    st.push(val);
  }

  void pop() {
    st.pop();
    mn.pop();
  }

  int top() {
    return st.top();
  }

  int getMin() {
    return mn.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */