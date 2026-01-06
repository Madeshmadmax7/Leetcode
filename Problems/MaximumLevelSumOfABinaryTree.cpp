/*
 * @lc app=leetcode id=1876596265 lang=cpp
 *
 * MaximumLevelSumOfABinaryTree
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(), sum = 0;

            while(n--) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);

                sum += current->val;
            }

            v.push_back(sum);
        }

        int index = 0, sum = INT_MIN;

        for(int i = 0; i < v.size(); i++) {
            if (v[i] > sum) {
                sum = v[i];
                index = i;
            }
        }

        return index + 1;
    }
};