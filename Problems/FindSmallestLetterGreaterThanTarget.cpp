/*
 * @lc app=leetcode id=1903234621 lang=cpp
 *
 * FindSmallestLetterGreaterThanTarget
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int size = letters.size();
        for(int i = 0; i < size; ++i)
            if (letters[i] > target) return letters[i];
        return letters[0];
    }
};