/*
 * @lc app=leetcode id=1910394757 lang=cpp
 *
 * MinimumRemovalsToBalanceArray
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
private:
    int findKtimes(int i,int k,vector<int>& v){
        
        int val;
        int l=i,h=v.size()-1;

        while(l<=h){
            int mid =l+(h-l)/2;

            if(v[mid]> (long long)k*v[i]){
                h=mid-1;
            }
            else{
                val=mid;
                l=mid+1;
            }
        }
        return val;
    }
public:
    int minRemoval(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        int ans = n-1;
        for(int i=0;i<n;i++){
            int x = findKtimes(i,k,v);
            ans=min(ans,i+n-x-1);
        }
        return ans;
    }
};