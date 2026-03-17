/*
 * @lc app=leetcode id=1951144640 lang=cpp
 *
 * LargestSubmatrixWithRearrangements
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
    private:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>right(n,n);
        vector<int>left(n,-1);

        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
            right[i]=st.top();

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
            left[i]=st.top();

            st.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }

        return ans;
    }
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0)continue;
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            sort(matrix[i].begin(),matrix[i].end());
            ans=max(ans,largestRectangleArea(matrix[i]));
        }
        return ans;
    }
};