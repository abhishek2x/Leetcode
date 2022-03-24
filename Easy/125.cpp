class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(char ch: s) {
            if(st.size() > 0) {
                if(st.top() == ch) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
            else st.push(ch);
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