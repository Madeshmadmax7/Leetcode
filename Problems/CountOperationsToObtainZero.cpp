/*
 * @lc app=leetcode id=1824943451 lang=cpp
 *
 * CountOperationsToObtainZero
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countOperations(int n1, int n2) {
        int c = 0;
        while (n1 > 0 && n2 > 0) {
            c += n1 / n2;
            n1 %= n2;
            swap(n1, n2);
        }
        return c;
    }
};