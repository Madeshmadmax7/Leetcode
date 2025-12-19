/*
 * @lc app=leetcode id=1859749381 lang=cpp
 *
 * FindAllPeopleWithSecret
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    void solve(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int, int>& m, int n){
        m[n] = 1;
        vis[n] = 1;
        for(auto& i : adj[n]){
            if(!vis[i]) solve(adj, vis, m, i);
        }
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        unordered_map<int, int> m;
        m[0] = 1;
        m[firstPerson] = 1;
        int j = 0;
        for(int i = 0;i<meetings.size();){
            int check = false;
            while(j<meetings.size() && meetings[j][2] == meetings[i][2]){
                if(m.count(meetings[j][0]) || m.count(meetings[j][1])){
                    check = true;
                    break;
                }
                j++;
            }
            if(check){
                j = i;
                unordered_map<int, vector<int>> adj;
                unordered_map<int, bool> vis;
                while(j<meetings.size() && meetings[j][2] == meetings[i][2]){
                    adj[meetings[j][0]].push_back(meetings[j][1]);
                    adj[meetings[j][1]].push_back(meetings[j][0]);
                    j++;
                }
                for(auto& i : adj){
                    if(m.count(i.first) && !vis[i.first]) solve(adj, vis, m, i.first);
                }
            }
            i = j;
        }
        vector<int> ans;
        for(auto& i : m) ans.push_back(i.first);
        return ans;
    }
};