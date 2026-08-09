class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones the current player can get
        // starting from index i with current M.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        function<int(int, int)> solve = [&](int i, int M) -> int {
            if (i >= n)
                return 0;

            // Can take all remaining piles.
            if (2 * M >= n - i)
                return suffix[i];

            if (dp[i][M] != -1)
                return dp[i][M];

            int best = 0;

            for (int X = 1; X <= 2 * M; ++X) {
                int nextM = max(M, X);

                // Total remaining stones - opponent's best score
                int current = suffix[i] - solve(i + X, nextM);

                best = max(best, current);
            }

            return dp[i][M] = best;
        };

        return solve(0, 1);
    }
};