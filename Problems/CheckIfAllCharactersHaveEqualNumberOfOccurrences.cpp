/*
 * @lc app=leetcode id=1892705697 lang=cpp
 *
 * CheckIfAllCharactersHaveEqualNumberOfOccurrences
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        sort(s.begin(),s.end());
        int c=1;
        vector<int>ct;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                c++;
            }
            else{
                ct.push_back(c);
                c=1;
            }
        }
        ct.push_back(c);
        int prev=ct[0];
        for(int i=1;i<ct.size();i++){
            if(ct[i]!=prev){
                return false;
            }
        }
        return true;
    }
};