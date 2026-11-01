class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low = *min_element(nums.begin(),nums.end());
        int moves =0;
        for(auto x : nums){
            moves += x - low;
        }
        return moves;
    }
};