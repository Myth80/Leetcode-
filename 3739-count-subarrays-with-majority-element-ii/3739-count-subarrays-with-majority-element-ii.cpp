class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==target)nums[i]=1;
            else nums[i]=-1;
        }
        vector<int>pS(n);
        pS[0]=nums[0];
        for(int i=1;i<n;i++){
            pS[i]=pS[i-1]+nums[i];
        }
        int shift = n;
        vector<int> freq(2*n+1,0);
        freq[shift]=1;
        long long valid=0;
        int lS = 0;
        for(int i=0;i<n;i++){
            if(pS[i]>lS){
                valid +=  freq[lS + shift];
            }else{
                valid -= freq[pS[i]+shift];
            }
            count += valid;
            freq[pS[i]+shift]++;
            lS = pS[i];
        }
        return count;
    }
};