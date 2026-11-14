class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        int i = n - 1;
        int j = n - 1;

        deque<int> dq;

        while (i >= 0) {

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int l = dq.back();
                dq.pop_back();

                int r = j + 1;

                if (!dq.empty()) {
                    r = dq.back();
                }

                cost += (long long)(r - l) * (nums[i] - nums[l]);
            }

            dq.push_back(i);

            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j) {
                    dq.pop_front();
                }

                j--;
            }

            ans += j - i + 1;

            i--;
        }

        return ans;
    }
};