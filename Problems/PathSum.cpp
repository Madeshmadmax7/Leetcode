/*
 * @lc app=leetcode id=1996200019 lang=cpp
 *
 * PathSum
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checksum(TreeNode* root,int tar,int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            return sum==tar;
        }
        return checksum(root->left,tar,sum)||checksum(root->right,tar,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checksum(root,targetSum,0);
    }
};