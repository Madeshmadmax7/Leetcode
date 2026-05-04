/*
 * @lc app=leetcode id=1994625954 lang=cpp
 *
 * BinaryTreeLevelOrderTraversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* front=que.front();
                que.pop();
                if(front->left!=NULL){
                    que.push(front->left);
                }
                if(front->right!=NULL){
                    que.push(front->right);
                }
                temp.push_back(front->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};