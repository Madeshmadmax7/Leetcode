/*
 * @lc app=leetcode id=1881884951 lang=cpp
 *
 * MaximalRectangle
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int check(vector<int> arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                ans = max(ans, arr[st.top()] * (i - pse[st.top()] - 1));
                st.pop();
            }
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) {
            ans = max(ans, arr[st.top()] * (n - pse[st.top()] - 1));
            st.pop();
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> a(m);

        for (int i = 0; i < m; i++) {
            a[i] = matrix[0][i] - '0';
        }

        int maxi = check(a);

        for (int i = 1; i < n; i++) {
            vector<int> a1(m, 0);
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != '0')
                    a1[j] = a[j] + 1;
                else
                    a1[j] = 0;
            }
            maxi = max(maxi, check(a1));
            a = a1;
        }

        return maxi;
    }
};