class Solution {
public:
    bool dfs(int src, int par, vector<vector<char>>& grid,
             vector<bool>& vis) {

        vis[src] = true;

        int m = grid.size();
        int n = grid[0].size();

        int r = src / n;
        int c = src % n;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if(grid[nr][nc] != grid[r][c])
                continue;

            int v = nr * n + nc;

            if(!vis[v]) {
                if(dfs(v, src, grid, vis))
                    return true;
            }
            else if(v != par) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bool> vis(m * n, false);

        for(int i = 0; i < m * n; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, grid, vis))
                    return true;
            }
        }

        return false;
    }
};