class Solution {
public:
    int f(int n , int m , vector<vector<int>>& oG , vector<vector<int>>& dp){
        if(n>=0 && m >=0 && oG[n][m]==1)return 0;
        if(n ==0 && m==0)return 1;
        if(n<0 || m<0)return 0;
        if(dp[n][m]!= -1)return dp[n][m];
        int left = f(n,m-1,oG , dp);
        int up = f(n-1,m,oG , dp);
        return dp[n][m] = left + up;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int n = oG.size();
        int m = oG[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,oG , dp);
    }
};