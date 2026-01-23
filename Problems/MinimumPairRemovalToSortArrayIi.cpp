/*
 * @lc app=leetcode id=1894464205 lang=cpp
 *
 * MinimumPairRemovalToSortArrayIi
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumPairRemoval(vector<int>& num) {
        int n = num.size();
        vector<long long> nums(n);
        for(int i = 0; i< n; i++){
            nums[i] = num[i];
        }
        int size = nums.size();
        vector<int> preIndex(size), postIndex(size);
        for(int i = 0; i < size; i++) {
            preIndex[i] = i - 1;
            postIndex[i] = i + 1;
        }
        set<pair<long long, int>> st;
        int targetPairs = 0;
        for(int i = 0; i < size - 1; i++) {
            if(nums[i] > nums[i + 1]) targetPairs++;
            st.insert({nums[i] + nums[i + 1], i});
        }
        int noOfOperations = 0;
        while(targetPairs > 0) {
            pair<long long, int> pr = *st.begin();
            st.erase(st.begin());
            int firstIndex = pr.second, secondIndex = postIndex[firstIndex];
            int leftFirstIndex = preIndex[firstIndex], rightSecondIndex = postIndex[secondIndex];
            if(nums[firstIndex] > nums[secondIndex]) targetPairs--;
            long long sum = pr.first;
            if(leftFirstIndex >= 0) {
                if(nums[leftFirstIndex] <= nums[firstIndex]) {
                    if(nums[leftFirstIndex] > sum) targetPairs++;
                }
                else {
                    if(nums[leftFirstIndex] <= sum) targetPairs--;
                }
                st.erase({nums[leftFirstIndex] + nums[firstIndex], leftFirstIndex});
                st.insert({nums[leftFirstIndex] + sum, leftFirstIndex});
            }
            if(rightSecondIndex < size) {
                if(nums[secondIndex] <= nums[rightSecondIndex]) {
                    if(sum > nums[rightSecondIndex]) targetPairs++;
                }
                else {
                    if(sum <= nums[rightSecondIndex]) targetPairs--;
                }
                st.erase({nums[secondIndex] + nums[rightSecondIndex], secondIndex});
                st.insert({sum + nums[rightSecondIndex], firstIndex});
                
                preIndex[rightSecondIndex] = firstIndex;
            }
            postIndex[firstIndex] = rightSecondIndex;
            nums[firstIndex] = sum;
            noOfOperations++;
        }

        return noOfOperations;
    }
};