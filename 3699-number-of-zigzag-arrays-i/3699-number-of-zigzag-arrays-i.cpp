class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;

        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> dp0(m), dp1(m);

        for (int i = 0; i < m; i++) {
            dp0[i] = i;
            dp1[i] = m - i - 1;
        }

        for (int len = 3; len <= n; len++) {

            long long total0 = 0;
            for (auto x : dp0)
                total0 = (total0 + x) % MOD;

            vector<long long> ndp0(m), ndp1(m);

            long long pref0 = 0;
            long long pref1 = 0;

            for (int i = 0; i < m; i++) {

                ndp0[i] = pref1;

                pref1 = (pref1 + dp1[i]) % MOD;

                pref0 = (pref0 + dp0[i]) % MOD;

                ndp1[i] = (total0 - pref0 + MOD) % MOD;
            }

            dp0.swap(ndp0);
            dp1.swap(ndp1);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + dp0[i] + dp1[i]) % MOD;
        }

        return (int)ans;
    }
};