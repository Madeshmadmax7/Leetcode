/*
 * @lc app=leetcode id=1969272598 lang=cpp
 *
 * LongestValidParentheses
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0;
        int ml=0;
        for(char c:s){
            if(c=='(') left++;
            else right++;
            if(left==right){
                ml=max(ml,right*2);
            }
            else if(right>left){
                left=right=0;
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') right++;
            else left++;
            if(left==right){
                ml=max(ml,left*2);
            }
            else if(left>right){
                left=right=0;
            }
        }
        return ml;
    }
};