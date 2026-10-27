class Solution {
public:
    static bool compare(string &a , string &b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int x : nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(), str.end(), compare);
        string maxNum;
        for(auto x  : str){
            maxNum +=x;
        }
        if (maxNum[0] == '0') return "0";
        return maxNum;
    }
};