class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oS = n*n;
        int eS = n * (n-1);
       
        return gcd(oS, eS);
    }
};