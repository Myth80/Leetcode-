
class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int drow = -1; drow <= 1; drow++) {
                for (int dcol = -1; dcol <= 1; dcol++) {

                    if (abs(drow) + abs(dcol) != 1)
                        continue;

                    int nrow = row + drow;
                    int ncol = col + dcol;

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' &&
                        !vis[nrow][ncol]) {

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};
