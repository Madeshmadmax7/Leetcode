/*
 * @lc app=leetcode id=1971293308 lang=cpp
 *
 * TrappingRainWater
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        rightMax[n-1]=height[n-1];
        for(int i=height.size()-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            int lM=leftMax[i],rM=rightMax[i];
            if(height[i]<lM&&height[i]<rM){
                total+=min(lM,rM)-height[i];
            }
        }
        return total;
    }
};