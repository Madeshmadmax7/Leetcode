/*
 * @lc app=leetcode id=1850826064 lang=cpp
 *
 * CountSpecialTriplets
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<long long, long long> leftCount, rightCount;
        long long result = 0;
        for (int num : nums) {
            rightCount[num]++;
        }
        for (int j = 0; j < nums.size(); j++) {
            rightCount[nums[j]]--;

            long long target = 2LL * nums[j];
            long long countLeft = leftCount[target];
            long long countRight = rightCount[target];

            result = (result + (countLeft * countRight) % MOD) % MOD;

            leftCount[nums[j]]++;
        }

        return (int)result;
    }
};