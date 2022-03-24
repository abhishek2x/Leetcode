class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char ch: s) {
            if(st.size() > 0) {
                if(st.top() != ch && (tolower(ch) == st.top() || toupper(ch) == st.top())) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            } else {
                st.push(ch);
            }
        }
        
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};