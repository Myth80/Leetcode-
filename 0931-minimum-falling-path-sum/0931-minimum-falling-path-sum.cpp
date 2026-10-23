class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
       
        int n = matrix.size();
        if (j < 0 || j >= n)
            return INT_MAX;
         if (i == 0)
            return matrix[0][j];
            if(dp[i][j]!=-10001)return dp[i][j];
        int up = f(i - 1, j, matrix, dp);
        int left = f(i - 1, j - 1, matrix, dp);
        int right = f(i - 1, j + 1, matrix, dp);
        int best = min(left, min(up, right));
        if(best==INT_MAX)return INT_MAX;
        return dp[i][j]=matrix[i][j] + best;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, (vector<int>(n, -10001)));
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(n - 1, j, matrix, dp));
        }
        return ans;
    }
};