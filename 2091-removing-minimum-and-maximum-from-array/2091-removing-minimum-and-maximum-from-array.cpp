class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int numMaxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int numMinIdx = min_element(nums.begin(), nums.end()) - nums.begin();

        //deleting max fron the front. numMaxIdx denoting the index of the number and + 1 for deleting that specific number as well
        int maxFront = numMaxIdx + 1;

        //deleting max at the back.n is size of arr - maxIdx (6 - 3) = 3 deletions.
        // eg ,1,2,3,6,4,5 , 6 at idx 3 (6-3) = 3. 3 deletions take place    
        int maxBack = n - numMaxIdx;
    
        //deleting min from front , index + 1 for no. of deletions
        int minFront = numMinIdx + 1;

        //deleting min at the back.n is size of arr - maxIdx (6 - 3) = 3 deletions.
        int minBack = n - numMinIdx;

        //max since we are deleting both elements from the front in one go
        int bothFront = max(maxFront, minFront);
        //max since we are deleting both elements from the back in one go.
        int bothBack = max(maxBack, minBack);
        //taking min since we dont know which route will be cheaper. going from front or from back.
        int oneEach = min(maxFront + minBack,
                          minFront + maxBack);

        return min({bothFront, bothBack, oneEach});
    }
};