// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n_temperatures = (int)temperatures.size();
        vector<int> answer(n_temperatures, 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < n_temperatures; i++) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                int previous_index = s.top().second;
                answer[previous_index] = i - previous_index;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return answer;
    }
};
