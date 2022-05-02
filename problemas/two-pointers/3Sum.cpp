// https://leetcode.com/problems/3sum/
class Solution {
 public:
  unordered_map<int, int> GetFrequencies(vector<int>& nums) {
    unordered_map<int, int> frequencies;
    for (int num : nums) {
      if (frequencies.count(num) == 0) {
        frequencies[num] = 0;
      }
      frequencies[num]++;
    }
    return frequencies;
  }

  vector<int> Compress(vector<int>& nums) {
    vector<int> sorted;
    for (int num : nums) sorted.push_back(num);
    sort(sorted.begin(), sorted.end());
    vector<int> compression = {sorted[0]};
    int n = (int)nums.size();
    for (int i = 1; i < n; i++) {
      if (sorted[i] != sorted[i - 1]) {
        compression.push_back(sorted[i]);
      }
    }
    return compression;
  }

  vector<int> GetTriplet(int x, int y, int z) {
    vector<int> triplet = {x, y, z};
    sort(triplet.begin(), triplet.end());
    return triplet;
  }

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;
    if (nums.size() < 3) return triplets;
    unordered_map<int, int> frequencies = GetFrequencies(nums);
    vector<int> compression = Compress(nums);
    int n = (int)compression.size();
    for (int i = 0; i < n; i++) {
      int num = compression[i];
      if (frequencies[num] >= 3) {
        if (3 * num == 0) {
          vector<int> triplet = GetTriplet(num, num, num);
          triplets.push_back(triplet);
        }
      }
      if (frequencies[num] >= 2) {
        int target = (-2) * num;
        if (target != num && frequencies.count(target) > 0) {
          vector<int> triplet = GetTriplet(num, num, target);
          triplets.push_back(triplet);
        }
      }
      int l = i + 1;
      int r = n - 1;
      while (l < r) {
        int sum = compression[l] + compression[r];
        if (sum + num == 0) {
          vector<int> triplet = GetTriplet(num, compression[l], compression[r]);
          triplets.push_back(triplet);
        }
        if (sum + num < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return triplets;
  }
};