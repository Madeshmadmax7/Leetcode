/*
 * @lc app=leetcode id=1908104351 lang=cpp
 *
 * TrionicArrayIi
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> nextIncreasing(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                nextIncreasing[i] = nextIncreasing[i + 1] + 1;
            }
        }

        vector<int> rightsm(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                rightsm[i] = rightsm[i + 1] + 1;
            }
        }


   
            vector<long long> thirdElemtmaxsum(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            thirdElemtmaxsum[i] = nums[i];
            if (i + 1 < n && nums[i] < nums[i + 1]) {
                thirdElemtmaxsum[i] = max(
                    (long long)nums[i],
                    nums[i] + thirdElemtmaxsum[i + 1]
                );
            }
        }
     

        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            int inc1 = nextIncreasing[i];
            if (inc1 == 0) continue;

            int idx1 = i + inc1;
            int dec = rightsm[idx1];
            if (dec == 0) continue;

            int idx2 = idx1 + dec;
            int inc2 = nextIncreasing[idx2];
            if (inc2 == 0) continue;

            long long sum;
            if (i == 0) {
                sum = prefix[idx2];
            } else {
                sum = prefix[idx2] - prefix[i - 1];
            }

         
            sum+=thirdElemtmaxsum[idx2+1];
            ans = max(ans, sum);
        }

     
        return ans;
    }
};