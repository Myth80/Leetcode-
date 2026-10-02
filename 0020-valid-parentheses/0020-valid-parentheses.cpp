class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(!st.empty()){
                char last = st.top();
                if((c==')' && last == '(') ||
                (c=='}' && last == '{') ||
                (c==']' && last =='[')){
                    st.pop();
                    continue;   
                }
            }
            st.push(c);
        }
        return st.empty();
    }
};