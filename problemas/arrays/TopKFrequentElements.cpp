class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = (int)nums.size();
    unordered_map<int, int> frequencies;
    for (int i = 0; i < n; i++) {
      if (frequencies.count(nums[i]) == 0) {
        frequencies[nums[i]] = 0;
      }
      frequencies[nums[i]]++;
    }
    vector<pair<int, int>> pairs;
    for (auto num_freq : frequencies) {
      int num = num_freq.first;
      int frequency = num_freq.second;
      pairs.push_back({frequency, num});
    }
    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());
    vector<int> top_k_frequent_elements;
    for (int i = 0; i < k; i++) {
      top_k_frequent_elements.push_back(pairs[i].second);
    }
    return top_k_frequent_elements;
  }
};