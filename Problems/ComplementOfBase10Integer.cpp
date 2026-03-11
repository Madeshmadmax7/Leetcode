/*
 * @lc app=leetcode id=1944963394 lang=cpp
 *
 * ComplementOfBase10Integer
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = 0;
        int j = 0;

        while(n > 0){
            int bit = n % 2;
            n /= 2;
            bit = (bit == 0) ? 1 : 0;
            ans += bit * (1 << j);
            j++;
        }

        return ans;
    }
};