class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1'000'000'007;
        int n = board.size();

        vector<vector<pair<int, int>>> dp(
            n, vector<pair<int, int>>(n, {-1, 0})
        );

        dp[n - 1][n - 1] = {0, 1};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int maxScore = -1;
                long long pathCount = 0;

                int dr[] = {1, 0, 1};
                int dc[] = {0, 1, 1};

                for (int k = 0; k < 3; ++k) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni >= n || nj >= n || dp[ni][nj].first == -1) {
                        continue;
                    }

                    if (dp[ni][nj].first > maxScore) {
                        maxScore = dp[ni][nj].first;
                        pathCount = dp[ni][nj].second;
                    } else if (dp[ni][nj].first == maxScore) {
                        pathCount = (pathCount + dp[ni][nj].second) % MOD;
                    }
                }

                if (maxScore == -1) {
                    continue;
                }

                int value = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                dp[i][j] = {maxScore + value, static_cast<int>(pathCount)};
            }
        }

        if (dp[0][0].first == -1) {
            return {0, 0};
        }

        return {dp[0][0].first, dp[0][0].second};
    }
};