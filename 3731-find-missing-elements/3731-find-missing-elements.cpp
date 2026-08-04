class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto x : nums){
            mp[x]++;
        }
        for(int i = mn;i<=mx;i++){
            if(mp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};