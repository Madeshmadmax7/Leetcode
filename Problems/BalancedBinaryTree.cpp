/*
 * @lc app=leetcode id=1912534180 lang=cpp
 *
 * BalancedBinaryTree
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
    private:
    int check(TreeNode* node){
        if(node==NULL)return 0;
        int lh=check(node->left);
        if(lh==-1)return -1;
        int rh=check(node->right);
        if(rh==-1)return -1;
        if(abs(lh-rh)>1)return -1;
        return 1+max(lh,rh);
    }
};