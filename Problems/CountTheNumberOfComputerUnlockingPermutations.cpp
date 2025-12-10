/*
 * @lc app=leetcode id=1851681674 lang=cpp
 *
 * CountTheNumberOfComputerUnlockingPermutations
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int MOD = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        int count = 0;
        for(int i=1; i<complexity.size(); i++){
            if(complexity[i] > complexity[0]){
                count++;
            }
            else{
                return 0;
            }
        }
        long long result = 1;
        for(long long i=count; i>=1; i--){
            result = (result * i) % MOD;
        }
        return (int)(result);
    }
};