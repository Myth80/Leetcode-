class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        int n = matrix.size();
        if (j < 0 || j >= n)
            return INT_MAX;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -19801)
            return dp[i][j];
        int best = INT_MAX;

        for (int k = 0; k < n; k++) {
            if (k == j)
                continue; // Cannot use the same column in consecutive rows

            int path = f(i - 1, k, matrix, dp);
            best = min(best, path);
        }
        if (best == INT_MAX)
            return INT_MAX;
        return dp[i][j] = matrix[i][j] + best;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, (vector<int>(n, -19801)));
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(n - 1, j, matrix, dp));
        }
        return ans;
    }
};