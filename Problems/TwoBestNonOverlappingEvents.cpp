/*
 * @lc app=leetcode id=1863286158 lang=cpp
 *
 * TwoBestNonOverlappingEvents
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort (events.begin(), events.end(), [] (const vector<int> & a, const vector<int>& b) {
            return a[0]<b[0];
        });

        int n=events.size();
        vector<int> best(n);
        best [n-1]=events[n-1][2];
        for(int i=n-2; i>=0; --i) {
            best[i]=max(events[i][2], best[i+1]);
        }
        vector<int> starts(n);
        for(int i=0; i<n; ++i) {
            starts[i]=events[i][0];
        }

        int ans=0;

        for(int i=0; i<n; ++i) {
            int start=events[i][0];
            int ent=events[i][1];
            int val=events[i][2];
            ans=max(ans, val);
            int j=upper_bound(starts.begin(), starts.end(), ent)-starts.begin();
            if (j<n) {
                ans=max(ans, val+best[j]);
            }
        }

        return ans;
    }
};