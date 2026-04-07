/*
 * @lc app=leetcode id=1971778901 lang=cpp
 *
 * NextGreaterElementI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>stk;
        int nge[n];
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&nums2[i]>stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                nge[i]=-1;
            }
            else{
                nge[i]=stk.top();
            }        
            stk.push(nums2[i]);
        }
        int m=nums1.size();
        vector<int>res(m);
        for(int i=0;i<m;i++){
            int val=nums1[i];
            for(int j=0;j<n;j++){
                if(val==nums2[j]){
                    res[i]=nge[j];
                    break;
                }
            }
        }
        return res;
    }
};