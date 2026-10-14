class Solution {
public:
    int f(int i , int j , vector<vector<int>>& oGrid, vector<vector<int>>& dp ){
        if(i>=0 && j >=0 && oGrid[i][j] == 1)return 0;
        if(i==0 && j ==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = f(i-1,j, oGrid , dp);
        int left = f(i,j-1,oGrid , dp);

        return dp [i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& oGrid) {
        int n = oGrid.size();
        int m = oGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));      
        return f(n-1,m-1,oGrid, dp);
    }
};