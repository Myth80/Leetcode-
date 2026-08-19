class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;

        for (auto &seat : reservedSeats) {
            rows[seat[0]].insert(seat[1]);
        }

        int ans = 2 * (n - rows.size());

        for (auto &[row, seats] : rows) {
            bool left = true;    // seats 2-5
            bool middle = true;  // seats 4-7
            bool right = true;   // seats 6-9

            for (int s = 2; s <= 5; s++)
                if (seats.count(s)) left = false;

            for (int s = 4; s <= 7; s++)
                if (seats.count(s)) middle = false;

            for (int s = 6; s <= 9; s++)
                if (seats.count(s)) right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};