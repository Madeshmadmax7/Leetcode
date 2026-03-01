/*
 * @lc app=leetcode id=1934915496 lang=cpp
 *
 * LongestCommonSubsequence
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int lcs(int i,int j,vector<vector<int>>&dp,string &s1,string&s2){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1+lcs(i-1,j-1,dp,s1,s2);
        return dp[i][j]=max(lcs(i-1,j,dp,s1,s2),lcs(i,j-1,dp,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=lcs(n-1,m-1,dp,text1,text2);
        return res;
    }
};