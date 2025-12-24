/*
 * @lc app=leetcode id=1864280679 lang=cpp
 *
 * AppleRedistributionIntoBoxes
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        
        int sum = 0;
        int answer = 0;
                for (int i : apple) {
            sum += i;
        }
        
        int n = capacity.size();
        for (int i = 0; i < n; i++) {
            answer++;
            sum -= capacity[i];
            if (sum <= 0) break;
        }
        return answer;
    }
};