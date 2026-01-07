/*
 * @lc app=leetcode id=1877760645 lang=cpp
 *
 * MaximumProductOfSplittedBinaryTree
 * 
 * Difficulty: Medium
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
 void totalsum(TreeNode* root,int &sum){
    if(root==nullptr){
        return;
    }
    sum+=root->val;
    totalsum(root->left,sum);
    totalsum(root->right,sum);
 }
 int solve(TreeNode* root,long long &maxi,int totalsum){
    if(root==nullptr){
        return 0;
    }
    int subtree=root->val;
    subtree+=solve(root->left,maxi,totalsum);
    subtree+=solve(root->right,maxi,totalsum);
   maxi=max(maxi,subtree*1LL*(totalsum-subtree));
   return subtree;
 }
  
    int maxProduct(TreeNode* root) {
        int sum=0;
        totalsum(root,sum);
        const int mod=1e9+7;
        long long maxi=0;
        solve(root,maxi,sum);
        return maxi%(mod);
    }
};