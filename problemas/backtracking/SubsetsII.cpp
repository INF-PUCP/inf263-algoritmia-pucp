// https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<pair<int, int>> nums_freqs;
    
    vector<pair<int, int>> Compress(const vector<int>& nums) {
        vector<pair<int, int>> compression;
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        int freq = 1;
        int n = (int)copy.size();
        
        for (int i = 1; i <= n; i++) {
            if (i == n || copy[i] != copy[i - 1]) {
                compression.push_back({copy[i - 1], freq});
                freq = 1;
            } else {
                freq++;
            }
        }
        
        return compression;
    }
    
    vector<vector<int>> subsets;
    vector<int> subset;
    
    void Backtrack(int i, int n) {
        if (i == n) {
            subsets.push_back(subset);
            return;
        }
        int num = nums_freqs[i].first;
        int cnt = nums_freqs[i].second;
        for (int j = 0; j <= cnt; j++) {
            if (j > 0) {
                subset.push_back(num);
            }
            Backtrack(i + 1, n);
        }
        for (int j = 0; j < cnt; j++) {
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        nums_freqs = Compress(nums);
        int n = (int)nums_freqs.size();
        Backtrack(0, n);
        return subsets;
    }
};
