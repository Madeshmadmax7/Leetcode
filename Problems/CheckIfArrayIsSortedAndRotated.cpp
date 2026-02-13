/*
 * @lc app=leetcode id=1918053881 lang=cpp
 *
 * CheckIfArrayIsSortedAndRotated
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0,temp=0;
        for(int i=0;i<n;i++){
            if(nums[i]>(nums[(i+1)%n])){
                count++;
                temp=i;
            }
        }
        bool ans=false;
        if(count<=1){
            ans=true;
        }
        else{
            ans=false;
        }
        return ans;
    }
};