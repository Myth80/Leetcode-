class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        string s = word1;
        string t = word2;

        int n = s.size();
        int m = t.size();

        vector<int> suffix(n + 1, 0);

        int j = m - 1;
        int matched = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) {
                matched++;
                j--;
            }

            suffix[i] = matched;
        }

        vector<int> ans(m);

        int i = 0;
        j = 0;

        while (i < n && j < m) {

            if (s[i] == t[j]) {
                ans[j] = i;
                j++;
            } else {
                if (suffix[i + 1] >= m - j - 1) {
                    ans[j] = i;
                    j++;
                    i++;
                    break;
                }
            }

            i++;
        }

        if (j < m && i == n)
            return {};

        while (i < n && j < m) {

            if (s[i] == t[j]) {
                ans[j] = i;
                j++;
            }

            i++;
        }

        if (j != m)
            return {};

        return ans;
    }
};