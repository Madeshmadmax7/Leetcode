/*
 * @lc app=leetcode id=1913593099 lang=cpp
 *
 * BalanceABinarySearchTree
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanced_Tree(vector<int>&arr,int low,int high){
        if(low==high){
            TreeNode* newNode=new TreeNode(arr[low]);
            return newNode;
        }
        if(low>high) return NULL;
        int mid=(low+(high-low)/2);
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=balanced_Tree(arr,low,mid-1);
        root->right=balanced_Tree(arr,mid+1,high);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int n=arr.size();
        root=balanced_Tree(arr,0,n-1);
        return root;
    }
};