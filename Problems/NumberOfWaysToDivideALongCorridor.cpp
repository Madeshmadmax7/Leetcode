/*
 * @lc app=leetcode id=1855528343 lang=cpp
 *
 * NumberOfWaysToDivideALongCorridor
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(string c) {
        int res=1;
        int seat=0;
        int i=0,n=c.size(),prev=0;
        while(i<n){
            int j=i;
            int cnt=0;
            while(j<n && cnt<2){
                if(c[j]=='S'){
                    seat++;
                    cnt++;}
                j++;
            }
            prev=j;
            while(j<n && c[j]!='S'){
                j++;
            }
            if(j<n)
              res=(1LL*res*(j-prev+1))%mod;
            i=j;  
        }
        if(seat<2 || seat%2) return 0;
        return res;
    }
};