class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int, int>> v1, v2;

        // Store coordinates of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1)
                    v1.push_back({i, j});

                if (img2[i][j] == 1)
                    v2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;

        int ans = 0;

        // Compare every 1 of img1 with every 1 of img2
        for (auto p1 : v1) {
            for (auto p2 : v2) {

                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};