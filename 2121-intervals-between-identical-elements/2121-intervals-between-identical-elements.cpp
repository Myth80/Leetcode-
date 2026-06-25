class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
         unordered_map<int , vector<int>>mp;
       for(int i=0;i<arr.size();i++){
        mp[arr[i]].push_back(i);
       }
        vector<long long>ans(arr.size() ,0);
        for(auto x : mp){
            vector<int>pos = x.second;
            int k = pos.size();
            vector<long long>pref(k+1 ,0);
            for(int i=0;i<k;i++){
                pref[i+1]=pref[i]+pos[i];
            }
            for(int i=0;i<k;i++){
                long long idx = pos[i];

                long long left = 1LL * i * idx - pref[i];
                long long right = (pref[k]-pref[i+1])- 1LL * (k-i-1)*idx;
                ans[idx] = left + right;
            }
        }
        return ans;
    }
};