class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<char> stk;
        unordered_set<char> inStack;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (inStack.count(c)) continue;

            while (!stk.empty() && stk.back() > c && last[stk.back() - 'a'] > i) {
                inStack.erase(stk.back());
                stk.pop_back();
            }

            stk.push_back(c);
            inStack.insert(c);
        }

        return string(stk.begin(), stk.end());
    }
};