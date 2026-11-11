class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long currCost = 0;
        long long singCost = 0;
        long long minCost = LLONG_MAX;
        singCost = (long long)need1 * cost1 + (long long)need2 * cost2;
        if (need1 > need2) {
            currCost = (long long)need2 * costBoth + (long long)(need1 - need2) * cost1;
        } else {
            currCost = (long long)need1 * costBoth + (long long)(need2 - need1) * cost2;
        }
        minCost = min(currCost, singCost);
        currCost = (long long)max(need1, need2) * costBoth;
        minCost = min(currCost, minCost);
        return minCost;
    }
};