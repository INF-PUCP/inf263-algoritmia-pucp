// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m{INT_MAX};
        int k{0};
        for (const int& e : nums) {
            if (k == 0) {
                m = e;
                k = 1;
            } else if (m == e) {
                k++;
            } else {
                k--;
            }
        }
        int cnt{0};
        for (const int& e : nums) {
            if (m == e) {
                cnt++;
            }
        }
        if (2 * cnt > nums.size()) {
            return m;
        }
        return INT_MAX;
    }
};