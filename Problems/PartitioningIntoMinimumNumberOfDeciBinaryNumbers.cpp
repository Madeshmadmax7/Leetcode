/*
 * @lc app=leetcode id=1934842965 lang=cpp
 *
 * PartitioningIntoMinimumNumberOfDeciBinaryNumbers
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minPartitions(string n) {
        char max='0';
        for(char c:n)
        {
            if(c>max) max=c;
        }
        return max - '0';
    }
};