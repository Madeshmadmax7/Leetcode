/*
 * @lc app=leetcode id=1937687655 lang=cpp
 *
 * SpecialPositionsInABinaryMatrix
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows=mat.size();
        int count=0;
        
        for(int i=0;i<rows;i++){
            int rowOnes=0;
            int colIndex=-1;

            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    rowOnes++;
                    colIndex=j;
                }
            }

            if(rowOnes==1){
                int colOnes=0;
                for(int k=0;k< rows;k++){
                    if(mat[k][colIndex]==1){
                        colOnes++;
                    }
                }
                if(colOnes==1){
                    count++;
                }
            }
        }
        return count;
    }
};