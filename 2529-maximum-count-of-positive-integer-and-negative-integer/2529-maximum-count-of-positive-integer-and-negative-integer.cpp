class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pCount = 0, nCount = 0;

        for (auto x : nums) {
            if (x > 0) {
                pCount++;
            }
            else if (x < 0) {
                nCount++;
            }
        }

        return max(pCount, nCount);
    }
};