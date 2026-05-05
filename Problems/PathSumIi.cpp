/*
 * @lc app=leetcode id=1996203560 lang=cpp
 *
 * PathSumIi
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
    void findpath(TreeNode* root, int target,vector<vector<int>>&res,vector<int>&temp,int sum){
        if(root==NULL) return;
        sum+=root->val;
        temp.push_back(root->val);
    
        if(root->left==NULL && root->right==NULL){
            if(sum==target)
            res.push_back(temp);
        }
        findpath(root->left,target,res,temp,sum);
        findpath(root->right,target,res,temp,sum);
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;
        findpath(root,targetSum,res,temp,0);
        return res;
    }
};