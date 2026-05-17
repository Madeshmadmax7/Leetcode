class Solution {
public:
    bool dfs(vector<int>&arr,int n,vector<int>&vis,int ind){
        if(ind<0||ind>=n||vis[ind]) return false;
        if(arr[ind]==0) return true;
        vis[ind]=1;
        return dfs(arr,n,vis,ind+arr[ind])||dfs(arr,n,vis,ind-arr[ind]);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        return dfs(arr,n,vis,start);
    }
};