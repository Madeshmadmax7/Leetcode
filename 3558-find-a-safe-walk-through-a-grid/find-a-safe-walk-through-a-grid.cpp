class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1) return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nh = h - grid[nr][nc];

                    if (nh > 0 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({nr, nc, nh});
                    }
                }
            }
        }

        return false;
    }
};