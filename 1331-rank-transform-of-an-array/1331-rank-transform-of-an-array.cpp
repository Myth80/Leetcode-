class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        vector<int> ans;
        int rank = 1;
        for (int x : temp) {
            if (mp.find(x) == mp.end()) {
                mp[x] = rank;
                rank++;
            }
        }
        for (auto x : arr) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};