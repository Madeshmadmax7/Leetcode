/*
 * @lc app=leetcode id=1864816204 lang=cpp
 *
 * MaximizeHappinessOfSelectedChildren
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int n = happiness.size();
        happiness.reserve(n + k);
        for (int i = 1; i < k; i++) {
            happiness.push_back(i);
        }
        nth_element(happiness.begin(), happiness.begin() + k, happiness.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            sum += (long long)happiness[i] - i;
        }
        return sum;
    }
};