/*
 * @lc app=leetcode id=1947034810 lang=cpp
 *
 * MinimumNumberOfSecondsToMakeMountainHeightZero
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canComplete(vector<int>& workerTimes, int mountainHeight, long long time) {
        int n = workerTimes.size();
        int x = mountainHeight;
        for (int i = 0; i < n; i++) {
            long long l = 1;
            long long r = mountainHeight;
            while(l <= r) {
                long long mid = l + (r-l)/2;
                if (mid*1ll*(mid+1) <= 2*time/workerTimes[i]) l = mid+1;
                else r = mid-1;
            }
            x -= r;
            if (x <= 0) return true;
        }
        if (x <= 0) return true;
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        if (n == 1) return (mountainHeight*1ll*(mountainHeight+1)/2)*workerTimes[0];
        if (mountainHeight == 1) return *min_element(workerTimes.begin(), workerTimes.end());
        long long maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1;
        long long r = maxTime*(mountainHeight*1ll*(mountainHeight-1)/2);
        long long ans = INT64_MAX;
        while(l <= r) {
            long long mid = l + (r-l)/2;
            
            if (canComplete(workerTimes, mountainHeight, mid)) {
                ans = min(ans, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};