
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        vector<int> freq(maxFactor + 1, 0);
        vector<int> multiples(maxFactor + 1, 0);

        // Step 1: Count factor frequencies
        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Step 2: Count multiples
        for (int i = 1; i <= maxFactor; i++) {
            if (freq[i] == 0) continue;

            for (int j = i; j <= maxFactor; j += i) {
                multiples[i] += freq[j];
            }
        }

        // Step 3: Sort by price
        sort(items.begin(), items.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        int ans = 0;

        // Step 4: Prioritize bonus purchases
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price >= 2LL * minPrice)
                break;

            int freeCount = multiples[factor] - 1;

            int buy = min(freeCount, budget / price);

            ans += 2 * buy;
            budget -= buy * price;
        }

        // Step 5: Spend remaining budget
        // on the cheapest item
        ans += budget / minPrice;

        return ans;
    }
};
