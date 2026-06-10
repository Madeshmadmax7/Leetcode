class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int tp=matrix[i][j]+dp[i+1][j];
                int tl=INT_MAX;
                if(j>0) tl=matrix[i][j]+dp[i+1][j-1];
                int tr=INT_MAX;
                if(j<n-1) tr=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min({tp,tl,tr});
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(dp[0][j],mini);
        }
        return mini;
    }
};