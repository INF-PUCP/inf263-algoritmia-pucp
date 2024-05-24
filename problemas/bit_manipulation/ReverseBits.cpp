// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0U;
        for (uint32_t i = 0U; i < 32U; i++) {
            uint32_t bit = (n >> i) & 1;
            result |= bit << (31 - i);
        }
        return result;
    }
};