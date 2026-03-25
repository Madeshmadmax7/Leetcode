/*
 * @lc app=leetcode id=1958743070 lang=cpp
 *
 * CountingBits
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int count(int n){
        int c=0;
        while(n>0){
            if(n&1) c++;
            n>>=1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            res.push_back(count(i));
        }
        return res;
    }
};