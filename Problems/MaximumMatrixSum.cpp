/*
 * @lc app=leetcode id=1875417987 lang=cpp
 *
 * MaximumMatrixSum
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int negCount=0;
        long long totalAbs=0;
        bool zeroExist=false;
        int minAbsNum=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int num=matrix[i][j];
                if(num==0){
                    zeroExist=true;
                }
                else if(num<0){
                    negCount++;
                }

                totalAbs+=abs(num);
                minAbsNum=min(minAbsNum,abs(num));
            }
        }

        if(zeroExist || negCount%2==0){
            return totalAbs;
        }
        else{
            return totalAbs - 2*minAbsNum;
        }
    }
};