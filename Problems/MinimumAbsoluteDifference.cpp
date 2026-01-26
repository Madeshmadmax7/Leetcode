/*
 * @lc app=leetcode id=1897568703 lang=cpp
 *
 * MinimumAbsoluteDifference
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int x=-1;
        int y=-1;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        {
            int temp=arr[i]-arr[i-1];
            if(temp<mini)
            {
                mini=temp;
            }
        }
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {
            int temp=arr[i]-arr[i-1];
            if(temp==mini)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return  ans;
    }
};