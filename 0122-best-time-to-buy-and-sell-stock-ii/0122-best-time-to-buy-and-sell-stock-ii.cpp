class Solution {
public:
    int f(int i , int b , vector<int>& prices , vector<vector<int>>&dp){
        if(i == prices.size())return 0;

        if(dp[i][b]!=-1)return dp[i][b];

        if(b==1){
            int buy = -prices[i]+f(i+1 , 0 , prices , dp);
            int skip = f(i+1, 1 , prices , dp);
            return dp[i][b]=max(buy, skip);
        }else{
            int sell = prices[i]+f(i+1 , 1, prices , dp);
            int skip = f(i+1 , 0 , prices , dp);
            return dp[i][b] = max(sell , skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};