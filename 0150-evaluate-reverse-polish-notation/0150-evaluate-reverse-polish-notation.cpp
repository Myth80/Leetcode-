class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int res =0;
        for(auto x:tokens){
            if(x=="+" || x=="-" || x=="*" || x=="/"){
                int first = st.top();
                st.pop();
                int sec = st.top();
                st.pop();
                if(x=="+"){
                    res = first + sec;
                }else if(x=="-"){
                    res = sec - first;
                }else if(x=="*"){
                    res = first * sec;
                }else{
                    res = sec / first;
                }
                st.push(res);
            }else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};