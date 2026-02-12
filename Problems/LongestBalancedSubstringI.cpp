/*
 * @lc app=leetcode id=1916953057 lang=cpp
 *
 * LongestBalancedSubstringI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isBalance(vector<int> &arr) {
        int common = 0;
        for(int i=0;i<26;i++) {
            if(arr[i]==0) {
                continue;
            }
            if(common==0) {
                common=arr[i];
            }
            else if(arr[i]!=common) {
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++) {
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++) {
                freq[s[j]-'a']++;

                if(isBalance(freq)) {
                    ans=max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};