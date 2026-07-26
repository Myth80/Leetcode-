class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int prod1, prod2;
        sort(nums.begin(),nums.end());
        prod1 = nums[n-1]*nums[n-2]*nums[n-3];
        prod2 = nums[0]*nums[1]*nums[n-1];
        int mp;
        mp=max(prod1,prod2);
        return mp;
    }
};