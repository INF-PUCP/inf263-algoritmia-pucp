// https://leetcode.com/problems/3sum/

class Solution {
   public:
    vector<int> Compress(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<int> compression;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                compression.push_back(nums[i - 1]);
            }
        }
        if (n > 0) compression.push_back(nums[n - 1]);
        return compression;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            if (frequencies.count(num) > 0) {
                frequencies[num]++;
            } else {
                frequencies[num] = 1;
            }
        }

        vector<vector<int>> triplets;
        vector<int> compression = Compress(nums);
        int n = (int)compression.size();
        for (int i = 0; i < n; i++) {
            int left = compression[i];

            // Case [0, 0, 0]
            if (frequencies[left] >= 3 && left == 0) {
                triplets.push_back({0, 0, 0});
            }

            // Case [left, left, -2left]
            if (frequencies[left] >= 2) {
                int right = (-2) * left;
                if (right > left && frequencies.count(right) > 0 && frequencies[right] > 0) {
                    triplets.push_back({left, left, right});
                }
            }

            // Case [left, mid, right]
            for (int j = i + 1; j < n; j++) {
                int mid = compression[j];
                int right = (-1) * (left + mid);
                if (right >= mid && (right == mid && frequencies[mid] >= 2 || right != mid && frequencies.count(right) > 0)) {
                    triplets.push_back({left, mid, right});
                }
            }
            frequencies[left] = 0;
        }
        return triplets;
    }
};