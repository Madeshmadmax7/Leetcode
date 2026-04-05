/*
 * @lc app=leetcode id=1969283672 lang=cpp
 *
 * FirstMissingPositive
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sm=1;
        for(int num:arr){
            if(num==sm){
                sm++;
            }
        }
        return sm;
    }
};