class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oS = 0, eS = 0;
        for (int i = 0; i <= 2 * n - 1; i += 2) {
            eS = eS + i;
        }
        for (int i = 1; i <= 2 * n - 1; i += 2) {
            oS = oS + i;
        }
        return gcd(oS, eS);
    }
};