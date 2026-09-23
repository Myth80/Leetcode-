class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int mSum = 0;

        for (auto n : nums)
            mSum += n;

        int target = mSum - x;

        if (target < 0)
            return -1;

        int len = 0;
        int left = 0;
        int curSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            curSum += nums[right];

            while (curSum > target) {
                curSum -= nums[left];
                left++;
            }

            if (curSum == target) {
                len = max(len, right - left + 1);
            }
        }

        if (len == 0 && target != 0)
            return -1;

        return nums.size() - len;
    }
};