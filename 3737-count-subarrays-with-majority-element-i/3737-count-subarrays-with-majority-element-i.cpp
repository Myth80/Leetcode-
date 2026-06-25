class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                nums[i]=+1;
            }else{
                nums[i]=-1;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j =i;j<nums.size();j++){
                sum += nums[j];
                if(sum > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};