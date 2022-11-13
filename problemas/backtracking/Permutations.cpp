// https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<bool> used;
    vector<int> permutation;
    vector<vector<int>> permutations;
    
    // ¿Dónde posiciono al elemento nums[pos]?
    void Backtrack(vector<int>& nums, int pos, int n) {
        // Casos hoja
        if (pos == n) {
            permutations.push_back(permutation);
            return;
        }
        
        // Para cada accion en el estado actual
        for (int i = 0; i < n; i++) {
            // Podamos
            if (used[i]) continue;
            
            // Actualizamos la informacion del estado actual
            permutation[i] = nums[pos];
            used[i] = true;
            
            // Nos movemos al siguiente estado
            Backtrack(nums, pos + 1, n);
            
            // Volvemos al estado actual desactualizando la informacion
            used[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();
        permutation = vector<int>(n);
        used = vector<bool>(n, false);
        Backtrack(nums, 0, n);
        return permutations;
    }
};
