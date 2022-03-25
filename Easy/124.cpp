class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res = "";
        int open=0, close=0;
        
        for(char ch: s) {
            st.push(ch);
            if(ch == '(') open++;
            if(ch == ')') close++;
            
            if(open == close) {
                string temp="";
                st.pop();
                
                while(st.size() > 1) temp += st.top(), st.pop();
                
                st.pop();
                reverse(temp.begin(), temp.end());
                res += temp;
                open=0; close=0;
            }
        }
        
        return res;
    }
};