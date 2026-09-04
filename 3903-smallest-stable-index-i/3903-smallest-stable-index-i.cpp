class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        int suffixMin = nums[n - 1];
        int ans = -1;

        for(int i = n - 1; i >= 0; i--) {
            suffixMin = min(suffixMin, nums[i]);

            if((long long)prefixMax[i] - suffixMin <= k) {
                ans = i;
            }
        }

        return ans;
    }
};