class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0 ,r =0 , maxLen =0 , maxFreq =0;
        unordered_map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            maxFreq = max(maxFreq,  freq[s[r]]);
            if((r-l+1) - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            if((r-l+1) - maxFreq <= k){
                maxLen = max(maxLen , r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};