/*
 * @lc app=leetcode id=1938869561 lang=cpp
 *
 * GenerateParentheses
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void gen(int n,int o,int c,string s,vector<string>&res){
        if(o==n&&c==n){
            res.push_back(s);
            return;
        }
        if(o<n){
            gen(n,o+1,c,s+"(",res);
        }
        if(c<n&&c<o){
            gen(n,o,c+1,s+")",res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        gen(n,0,0,"",res);
        return res;
    }
};