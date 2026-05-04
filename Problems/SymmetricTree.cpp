/*
 * @lc app=leetcode id=1994618275 lang=cpp
 *
 * SymmetricTree
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
    bool check(TreeNode* p,TreeNode*q){
        if(p==NULL||q==NULL){
            return p==q;
        }
        return (p->val==q->val)&&check(p->left,q->right)&&check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* rl=root->left;
        TreeNode* rr=root->right;
        return check(rl,rr);
    }
};