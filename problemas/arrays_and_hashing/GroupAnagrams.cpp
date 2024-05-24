class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = (int)strs.size();
    unordered_map<string, int> indices;
    vector<vector<string>> anagrams;
    for (int i = 0; i < n; i++) {
      string copy = strs[i];
      sort(copy.begin(), copy.end());
      if (indices.count(copy) == 0) {
        int index = (int)indices.size();
        indices[copy] = index;
        anagrams.push_back({});
      }
      anagrams[indices[copy]].push_back(strs[i]);
    }
    return anagrams;
  }
};