class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(char ch: s) {
            if(!st.empty() && ch == st.top().first) {
                st.top().second++;
                if(st.top().second == k) 
                    st.pop();
            }
            else {
                st.push({ch, 1});
            }
        }
        
        s="";
        while(!st.empty()) {
            while(st.top().second--) {
                s += st.top().first;
            }
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};