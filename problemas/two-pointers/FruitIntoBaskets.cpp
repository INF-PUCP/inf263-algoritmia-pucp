class Solution {
public:
  void Add(int value, map<int, int>& frequency) {
    if (frequency.count(value) > 0) {
      frequency[value]++;
    } else {
      frequency[value] = 1;
    }
  }
  
  void Delete(int value, map<int, int>& frequency) {
    frequency[value]--;
    if (frequency[value] == 0) frequency.erase(value);
  }
  
  int totalFruit(vector<int>& fruits) {
    int n = (int) fruits.size();
    int l = 0;
    map<int, int> frequency;
    int max_range = 0;
    for (int r = 0; r < n; r++) {
      Add(fruits[r], frequency);
      while (l <= r && frequency.size() > 2) {
        Delete(fruits[l], frequency);
        l++;
      }
      max_range = max(max_range, r - l + 1);
    }
    return max_range;
  }
};