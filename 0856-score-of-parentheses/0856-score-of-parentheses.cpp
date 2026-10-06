class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(auto x:s){
            if(x=='('){
                st.push(0);
            }
            else{
                int inside = st.top();
                st.pop();
    
            int score = (inside== 0)?1:2*inside;

            st.top() += score;
        }
        }
        return st.top();
    }
};