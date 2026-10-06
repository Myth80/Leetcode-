class Solution {
public:

    bool fn(vector<int>& stones, vector<vector<int>>& dp,
            int i, int jump) {

        //  edge case for last stone
        if (i == stones.size() - 1)
            return true;

        //if already in dp
        if (dp[i][jump] != -1)
            return dp[i][jump];

        bool left = false;
        bool curr = false;
        bool right = false;

        // jump - 1
        if (jump - 1 > 0) {

            int next = stones[i] + jump - 1;

            for (int j = i + 1; j < stones.size(); j++) {

                if (stones[j] == next) {
                    left = fn(stones, dp, j, jump - 1);
                    break;
                }

                if (stones[j] > next)
                    break;
            }
        }

        // jump
        if (jump > 0) {

            int next = stones[i] + jump;

            for (int j = i + 1; j < stones.size(); j++) {

                if (stones[j] == next) {
                    curr = fn(stones, dp, j, jump);
                    break;
                }

                if (stones[j] > next)
                    break;
            }
        }

        // jump + 1
        {
            int next = stones[i] + jump + 1;

            for (int j = i + 1; j < stones.size(); j++) {

                if (stones[j] == next) {
                    right = fn(stones, dp, j, jump + 1);
                    break;
                }

                if (stones[j] > next)
                    break;
            }
        }

        return dp[i][jump] = left || curr || right;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();

        if (n > 1 && stones[1] != 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fn(stones, dp, 0, 0);
    }
};