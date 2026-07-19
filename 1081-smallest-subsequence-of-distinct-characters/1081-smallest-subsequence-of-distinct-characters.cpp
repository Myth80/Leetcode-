class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<int> vis(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            freq[s[i] - 'a']--;

            if (vis[s[i] - 'a']) {
                continue;
            }

            while (!ans.empty() &&
                   ans.back() > s[i] &&
                   freq[ans.back() - 'a'] > 0) {

                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans += s[i];
            vis[s[i] - 'a'] = 1;
        }

        return ans;
    }
};