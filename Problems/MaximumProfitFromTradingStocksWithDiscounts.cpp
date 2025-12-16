/*
 * @lc app=leetcode id=1857093285 lang=cpp
 *
 * MaximumProfitFromTradingStocksWithDiscounts
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution{
public:
    vector<vector<int>>adjList;
    vector<int>present;
    vector<int>future;
    int budget;
    vector<vector<vector<int>>>dp;

    void updateBudgetProfile(vector<int>&curr,vector<int>&child){
        vector<int>temp(budget+1,0);
        
        for(int b=0;b<=budget;b++){
            for(int i=0;i<=b;i++){
                int j=b-i;
                temp[b]=max(temp[b],curr[i]+child[j]);
            }
        }

        curr=temp;
    }

    void dfs(int curr_node){
        for(int child_node:adjList[curr_node]){
            dfs(child_node);
        }

        for(int discount=0;discount<=1;discount++){
            int price=present[curr_node];
            if(discount){
                price/=2;
            }
            vector<int>notTake(budget+1,0);
            for(int child_node:adjList[curr_node]){
                updateBudgetProfile(notTake,dp[child_node][0]);
            }

            vector<int>take(budget+1,0);
            if(price<=budget){
                vector<int>budgetProfile(budget+1,0);
                for(int child_node:adjList[curr_node]){
                    updateBudgetProfile(budgetProfile,dp[child_node][1]);
                }

                int profit=future[curr_node]-price;

                for(int i=price;i<=budget;i++){
                    take[i]=budgetProfile[i-price]+profit;
                }
            }

            for(int i=0;i<=budget;i++){
                dp[curr_node][discount][i]=max(take[i],notTake[i]);
            }
        }
    }
    
    int maxProfit(int n,vector<int>&p,vector<int>&f,vector<vector<int>>&edges,int b){
        present=p;
        future=f;
        budget=b;
        adjList.resize(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            u--;v--;

            adjList[u].push_back(v);
        }   

        dp=vector<vector<vector<int>>>(n,
        vector<vector<int>>(2,vector<int>(budget+1,0)));
        dfs(0);

        int ans=0;
        for(int i=0;i<=budget;i++){
            ans=max(ans,dp[0][0][i]);
        }

        return ans;
    }
};