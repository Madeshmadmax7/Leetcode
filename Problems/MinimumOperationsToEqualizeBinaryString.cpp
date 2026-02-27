/*
 * @lc app=leetcode id=1932880233 lang=cpp
 *
 * MinimumOperationsToEqualizeBinaryString
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int initialZeros = 0;

        for (char ch: s) {
            if (ch == '0') {
                initialZeros++;
            }
        }

        if (initialZeros == 0) {
            return 0;
        }

        vector<int> operations(n + 1, -1);
        set<int> evenSet, oddSet;

        for (int cnt = 0; cnt <= n; cnt++) {
            if (cnt % 2 == 0) evenSet.insert(cnt);
            else oddSet.insert(cnt);
        }

        operations[initialZeros] = 0;
        queue<int> q;
        q.push(initialZeros);

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int minVal = max(0, k - n + z);
            int maxVal = min(z, k);

            int min_new_z = z + k - (2 * maxVal);
            int max_new_z = z + k - (2 * minVal);

            set<int> &currSet = (min_new_z % 2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);
            while (it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;
                    if (newZ == 0) {
                        return operations[newZ];
                    }

                    q.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return operations[0];
    }
};