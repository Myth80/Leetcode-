class Solution {
public:
    int minPrice = INT_MAX;
    vector<int> gain;

    int f(int n, int m, int b, vector<vector<int>>& items,
          vector<vector<int>>& dp) {
        if (b == 0)
            return 0;
        if (n == m)
            return b / minPrice;

        if (dp[n][b] != -1)
            return dp[n][b];

        int notpick = f(n + 1, m, b, items, dp);

        int pick = 0;

        if (b >= items[n][1]) {
            pick = gain[n] + f(n + 1, m, b - items[n][1], items, dp);
        }

        return dp[n][b] = max(pick, notpick);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        gain.resize(n, 0);

        for (int i = 0; i < n; i++) {

            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    gain[i]++;
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));

        return f(0, n, budget, items, dp);
    }
};