class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int l=0;
        while(l<nums.size()){
            int digsum=0;
                int digit = nums[l];
                while(digit>0){
                digsum = digsum +  digit%10;
                digit = digit/10;
                }
            if(digsum == l){
                return l;
            }else{
            l++;
            }
        }
        return -1;
    }
};