/*
 * @lc app=leetcode id=1935684440 lang=cpp
 *
 * MinimumSwapsToArrangeABinaryGrid
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>a(n);
        int j=n-1;
        for(int i=0;i<a.size();i++){
            a[i]=j;
            j--;
        }
        vector<int>b;
        for(int i=0;i<n;i++){
            int j=n-1;
            int l=0;
            while(j>=0 && grid[i][j]==0){
                l++;
                j--;
            }
            b.push_back(l);
        }
        int y=0;
        
        for(int i=0;i<n;i++){
            if(a[i]<=b[i]){
                continue;
            }
            int j=i;
            
            while(j<n && b[j]<a[i]){
                j++;
            }
            if(j==n) return -1;
            while(j>i){
                swap(b[j],b[j-1]);
                y++;
                j--;
            }
        }
        
        return y;
    }
};