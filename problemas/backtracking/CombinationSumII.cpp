// https://leetcode.com/problems/combination-sum-ii/
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
    
    vector<vector<int>> combinations;
    vector<int> combination;
    
    void Backtrack(int i, int n, int t) {
        if (t == 0) {
            combinations.push_back(combination);
            return;
        }
        if (t < 0 || i == n) return;
        int num = nums_freqs[i].first;
        int freq = nums_freqs[i].second;
        for (int j = 0; j <= freq; j++) {
            if (j > 0) {
                combination.push_back(num);
                t -= num;
            }
            Backtrack(i + 1, n, t);
        }
        for (int j = 0; j < freq; j++) {
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums_freqs = Compress(candidates);
        int n = (int)nums_freqs.size();
        Backtrack(0, n, target);
        return combinations;
    }
};
