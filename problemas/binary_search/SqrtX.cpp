// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    typedef long long Long;
    int mySqrt(int x) {
        Long left = 0;
        Long right = 47000;
        while (right - left > 1) {
            Long mid = (left + right) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};