class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        int n = nums.size();

        for(int len=l; len<=r; len++){
            int sum = 0;

            for(int i=0; i<len; i++){
                sum += nums[i];
            }

            if(sum > 0){
                minSum = min(minSum, sum);
            }

            for(int i=len; i<n; i++){
                sum += nums[i];
                sum -= nums[i-len];

                if(sum > 0){
                    minSum = min(minSum, sum);
                }
            }
        }

        if(minSum == INT_MAX){
            return -1;
        }

        return minSum;
    }
};