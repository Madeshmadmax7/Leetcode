/*
 * @lc app=leetcode id=1938896546 lang=cpp
 *
 * BinaryTreeMaximumPathSum
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int ms=INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left=max(0,dfs(root->left));
        int right=max(0,dfs(root->right));
        ms=max(ms,left+root->val+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ms;
    }
};