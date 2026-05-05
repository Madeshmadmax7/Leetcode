/*
 * @lc app=leetcode id=1995991255 lang=cpp
 *
 * MergeIntervals
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(auto &it:intervals){
            if(ans.empty()||it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }
        }
        return ans;
    }
};