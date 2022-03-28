const int MAX_TEMPERATURE = 100;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> minimum_time(MAX_TEMPERATURE + 1, INT_MAX);
    int days = T.size();
    vector<int> result(days, 0);
    for (int i = days - 1; i >= 0; i--) {
      int minimum = INT_MAX;
      for (int day = T[i] + 1; day <= MAX_TEMPERATURE; day++) {
        minimum = min(minimum, minimum_time[day]);
      }
      if (minimum < INT_MAX) {
        result[i] = minimum - i;
      }
      minimum_time[T[i]] = i;
    }
    return result;
  }
};
