/*
 * @lc app=leetcode id=1849371135 lang=cpp
 *
 * CountOddNumbersInAnIntervalRange
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countOdds(int low, int high) {
        int a=low%2;
        int b=high%2;

        if(a==0 && b==0){
            return (high-low)/2;
        }
        if(a==1 && b==1){
            return (high-low)/2 + 1;
        }else{
            return (high-low+1)/2;
        }
    }
};