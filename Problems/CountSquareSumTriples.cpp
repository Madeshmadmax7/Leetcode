/*
 * @lc app=leetcode id=1850262848 lang=cpp
 *
 * CountSquareSumTriples
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countTriples(int n) {
        unordered_map<int,int> mp;
        vector<int> squareNum;
        for(int i = 1; i <= n; i++)
        {
            mp[i*i] = 1;
            squareNum.push_back(i*i);
        }

        int count = 0;
        for(int i = squareNum.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < i; j++)
            {
                if(mp.find(squareNum[i] + squareNum[j]) != mp.end())
                {
                    count += 2;
                }
            }
        }
        return count;
    }
};