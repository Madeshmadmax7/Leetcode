/*
 * @lc app=leetcode id=1928471267 lang=cpp
 *
 * CheckIfAStringContainsAllBinaryCodesOfSizeK
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string >st;
        if(k>=s.size())return false;
        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i, k));
        }return pow(2 , k)==st.size();
    }
};