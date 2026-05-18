class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                int ind = q.front();
                q.pop();

                if(ind == n - 1){
                    return steps;
                }

                for(int next : mp[arr[ind]]){

                    if(!vis[next]){
                        vis[next] = 1;
                        q.push(next);
                    }
                }

                if(ind - 1 >= 0 && !vis[ind - 1]){
                    vis[ind - 1] = 1;
                    q.push(ind - 1);
                }

                if(ind + 1 < n && !vis[ind + 1]){
                    vis[ind + 1] = 1;
                    q.push(ind + 1);
                }

                mp[arr[ind]].clear();
            }

            steps++;
        }

        return -1;
    }
};