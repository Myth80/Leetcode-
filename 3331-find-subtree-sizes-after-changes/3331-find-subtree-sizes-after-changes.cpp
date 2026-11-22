
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';
            int prev = last[c];
            last[c] = node;

            for (int child : tree[node]) {
                dfs(child);
            }

            last[c] = prev;

            if (node != 0) {
                int p = (prev == -1) ? parent[node] : prev;
                ans[p] += ans[node];
            }
        };

        dfs(0);
        return ans;
    }
};
