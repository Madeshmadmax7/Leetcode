/*
 * @lc app=leetcode id=1911384766 lang=cpp
 *
 * MinimumDeletionsToMakeStringBalanced
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0;
        stack<char>st;
        for(char c:s){
            if(c=='b'){
                st.push(c);
            }else{
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    cnt++;
                }
            }
        }
        return cnt;
    }
};