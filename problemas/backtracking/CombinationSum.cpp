// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> combination;
    
    void Backtrack(vector<int>& nums, int pos, int n, int target) {
        // Si ya he tengo una combinacion con la suma objetivo, la guardamos
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        
        // Si ya no tenemos elementos por escoger o nos hemos pasado del objetivo, retornamos
        if (target < 0 || pos == n) return;
        
        // Ignoramos el elemento actual
        Backtrack(nums, pos + 1, n, target);
        
        // Coloco multiples ejemplares del elemento actual
        combination.push_back(nums[pos]);
        Backtrack(nums, pos, n, target - nums[pos]);
        combination.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = (int)candidates.size();
        Backtrack(candidates, 0, n, target);
        return combinations;
    }
};
