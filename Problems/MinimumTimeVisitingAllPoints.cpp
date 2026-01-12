/*
 * @lc app=leetcode id=1882895024 lang=cpp
 *
 * MinimumTimeVisitingAllPoints
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            totalTime += max(dx, dy);
        }
        
        return totalTime;
    }
};