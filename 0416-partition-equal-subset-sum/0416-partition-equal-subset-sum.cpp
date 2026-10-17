class Solution {
public:
    bool f(int idx , int k , vector<int>&nums , vector<vector<int>>&dp){
        if (idx == 0) return nums[0] == k;
        if(k == 0)return true;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int notTake = f(idx - 1, k , nums, dp);
        int take = false;
        if(k>=nums[idx]){
            take = f(idx - 1 , k-nums[idx], nums,dp);
        }
        return dp[idx][k]= take || notTake; 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tSum = 0;
        for(int i=0;i<n;i++){
            tSum += nums[i];
        }
        if (tSum % 2 != 0) return false;
        int target = tSum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n-1 ,target , nums, dp);
    }
};