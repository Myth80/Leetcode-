class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string curr= "";
        for(auto x : s){
            if(x=='('){
                st.push(curr);
                curr="";
            }
            else if(x==')'){
                reverse(curr.begin(),curr.end());
                curr = st.top() +curr;
                st.pop();
            }else{
                curr +=x;
            }
        }
        return curr;
    }
};