/*
 * @lc app=leetcode id=1985845121 lang=cpp
 *
 * SumOfDistances
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &p : mp){
            vector<int> &v = p.second;
            int m = v.size();

            vector<long long> prefix(m, 0);
            prefix[0] = v[0];
            for(int i = 1; i < m; i++){
                prefix[i] = prefix[i-1] + v[i];
            }

            for(int i = 0; i < m; i++){
                long long left = (long long)v[i] * i - (i > 0 ? prefix[i-1] : 0);
                long long right = (prefix[m-1] - prefix[i]) - (long long)v[i] * (m - i - 1);

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};