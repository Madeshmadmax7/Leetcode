/*
 * @lc app=leetcode id=1887956357 lang=cpp
 *
 * FindTheLargestAreaOfSquareInsideTwoRectangles
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int maxi = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = max(bottomLeft[j][0], bottomLeft[i][0]);
                int x2 = min(topRight[j][0], topRight[i][0]);
                int y1 = max(bottomLeft[j][1], bottomLeft[i][1]);
                int y2 = min(topRight[j][1], topRight[i][1]);
                if (x2 > x1 && y2 > y1)
                    maxi = max(maxi,min(x2 - x1, y2 - y1));
            }
        }
        return ((long long)maxi) * ((long long)maxi);
    }
};