// https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(int n) {
        int weight = 0;
        while (n > 0) {
            weight += n & 1;
            n >>= 1;
        }
        return weight;
    }
};