class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum =0 , rSum =0 , mSum=0;
        for(int i=0;i<k;i++){
            lSum += cardPoints[i];
            mSum = lSum;
        }
        int r = n-1;
        for(int i = k-1;i>=0;i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[r];
            r--;
    
        mSum = max(mSum , lSum + rSum);
        }
        return mSum;
    }
};