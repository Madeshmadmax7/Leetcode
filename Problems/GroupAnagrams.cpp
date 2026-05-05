/*
 * @lc app=leetcode id=1995962215 lang=cpp
 *
 * GroupAnagrams
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string &s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto & entry:mp){
            res.push_back(entry.second);
        }
        return res;
    }
};