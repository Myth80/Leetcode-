class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int in = 1 , d=1 , ans = 1;

        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                in++;
                d=1;
            }else if(arr[i]<arr[i-1]){
                d++;
                in = 1;
            }else{
                in =1;
                d=1;
            }
            ans = max(ans,max(in , d));
        }
        return ans;
        
    }
};