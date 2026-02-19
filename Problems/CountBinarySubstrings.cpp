/*
 * @lc app=leetcode id=1924401837 lang=cpp
 *
 * CountBinarySubstrings
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countBinarySubstrings(string s) {
      int pre = 0, curr = 1, ans = 0;
      for( int i = 1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            curr++;
        }else{
        ans += min(pre, curr);
        pre = curr;
        curr = 1;
        }
      }
      ans += min(pre,curr);
      return ans; 
    }
};