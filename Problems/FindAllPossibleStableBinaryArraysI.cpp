/*
 * @lc app=leetcode id=1942842387 lang=cpp
 *
 * FindAllPossibleStableBinaryArraysI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int MOD = 1e9 + 7, lmt;
    long long dp[205][205][2];

    long long go(int z, int o, bool lst){
        if(z == 0 && o == 0) return 1;

        long long &ret = dp[z][o][lst];
        if(~ret) return ret;

        ret = 0;
        if(lst == 0){
            int mx = min(o, lmt);
            for(int k=1; k<=mx; k++){
                ret += go(z, o - k, 1);
                ret %= MOD;
            }
        }
        else {
            int mx = min(z, lmt);
            for(int k=1; k<=mx; k++){
                ret += go(z - k, o, 0);
                ret %= MOD;
            }
        }

        return ret;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        lmt = limit;
        memset(dp, -1, sizeof(dp));

        long long ans = (go(zero, one, 1) + go(zero, one, 0)) % MOD;
        return ans;
    }
};