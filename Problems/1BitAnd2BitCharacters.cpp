/*
 * @lc app=leetcode id=1833273284 lang=cpp
 *
 * 1BitAnd2BitCharacters
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int n=bits.size();
        int i=0;
        for(; i<n-1; i++){
            if(bits[i]==1) i++;
        }
        return i==n-1;
    }
};