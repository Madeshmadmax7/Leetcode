/*
 * @lc app=leetcode id=1942986209 lang=cpp
 *
 * LongestSubstringWithoutRepeatingCharacters
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int arr[256];
        for(int i=0;i<256;i++) arr[i]=-1;

        int left=0,maxlen=0;

        for(int right=0; right<s.size(); right++){

            if(arr[s[right]] >= left)
                left = arr[s[right]] + 1;

            arr[s[right]] = right;

            maxlen = max(maxlen, right-left+1);
        }

        return maxlen;
    }
};