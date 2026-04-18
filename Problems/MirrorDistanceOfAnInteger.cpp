/*
 * @lc app=leetcode id=1981849127 lang=cpp
 *
 * MirrorDistanceOfAnInteger
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        for(int x=n; x; x/=10){
            rev=10*rev+x%10;
        }
        rev-=n;
        return rev>=0?rev:-rev;
    }
};