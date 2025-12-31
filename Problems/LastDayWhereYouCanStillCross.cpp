/*
 * @lc app=leetcode id=1870291832 lang=cpp
 *
 * LastDayWhereYouCanStillCross
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>&grid){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return false;
        if(grid[i][j]==1) return false;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                if(r==grid.size()-1) return true;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]==0&&!vis[nr][nc]){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int l=0,h=n;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            vector<vector<int>> grid(row,vector<int>(col,0));
            for(int i=0;i<mid;i++){
                grid[cells[i][0]-1][cells[i][1]-1]=1;
            }
            bool ok=false;
            for(int j=0;j<col;j++){
                if(bfs(0,j,grid)){
                    ok=true;
                    break;
                }
            }
            if(ok){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};