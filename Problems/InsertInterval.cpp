/*
 * @lc app=leetcode id=1996001683 lang=cpp
 *
 * InsertInterval
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
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