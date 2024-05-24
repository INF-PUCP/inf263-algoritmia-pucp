// https://leetcode.com/problems/counting-bits/
class Solution {
private:
    int hammingWeight(int n) {
        int weight = 0;
        while (n > 0) {
            weight += (n & 1);
            n >>= 1;
        }
        return weight;
    }
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for (int i = 0; i <= n; i++) {
            bits.push_back(hammingWeight(i));
        }
        return bits;
    }
};