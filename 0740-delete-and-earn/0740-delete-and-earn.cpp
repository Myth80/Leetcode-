class Solution {
public:
    int f(int idx, vector<int>& points, vector<int>& dp) {
        if (idx == 0)
            return points[0];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pick = points[idx] + f(idx - 2, points, dp);
        int notpick = f(idx - 1, points, dp);

        return dp[idx] = max(pick, notpick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return f(maxi, points, dp);
    }
};
