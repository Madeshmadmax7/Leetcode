/*
 * @lc app=leetcode id=1955856916 lang=cpp
 *
 * DetermineWhetherMatrixCanBeObtainedByRotation
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        for(int i=0;i<4;i++){
            rotate(mat);
            if(mat == target) return true;
        }
        return false;
    }
};