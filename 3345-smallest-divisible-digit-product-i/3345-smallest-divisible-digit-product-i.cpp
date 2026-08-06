class Solution {
public:
    int prod(int x) {
        string s = to_string(x);
        int p = 1;

        for (char c : s) {
            p *= (c - '0');
        }

        return p;
    }

    int smallestNumber(int n, int t) {
        while (prod(n) % t != 0) {
            n++;
        }
        return n;
    }
};