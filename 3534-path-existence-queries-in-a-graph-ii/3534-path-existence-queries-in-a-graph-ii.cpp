class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> values(n), pos(n);

        for (int i = 0; i < n; i++) {
            values[i] = nums[order[i]];
            pos[order[i]] = i;
        }

        vector<int> component(n, 0);
        for (int i = 1; i < n; i++) {
            component[i] = component[i - 1] +
                           (values[i] - values[i - 1] > maxDiff);
        }

        vector<int> farthest(n);
        int right = 0;

        for (int i = 0; i < n; i++) {
            right = max(right, i);

            while (right + 1 < n &&
                   values[right + 1] - values[i] <= maxDiff) {
                right++;
            }

            farthest[i] = right;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> jump(LOG, vector<int>(n));
        jump[0] = farthest;

        for (int bit = 1; bit < LOG; bit++) {
            for (int i = 0; i < n; i++) {
                jump[bit][i] = jump[bit - 1][jump[bit - 1][i]];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = pos[query[0]];
            int v = pos[query[1]];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            if (u > v) swap(u, v);

            if (component[u] != component[v]) {
                answer.push_back(-1);
                continue;
            }

            int steps = 0;
            int current = u;

            for (int bit = LOG - 1; bit >= 0; bit--) {
                if (jump[bit][current] < v) {
                    current = jump[bit][current];
                    steps += (1 << bit);
                }
            }

            answer.push_back(steps + 1);
        }

        return answer;
    }
};