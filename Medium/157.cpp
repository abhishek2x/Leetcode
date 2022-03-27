class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<bool> isVisited(26, false);
        vector<int> lastIndex(26);
        
        for(int i=0; i<size(s); i++) lastIndex[s[i] - 'a'] = i;
        
        for(int i=0; i<size(s); i++) {
            char ch = s[i];
            
            if(isVisited[ch-'a']) continue;
            
            while(!st.empty() && st.top() > ch && lastIndex[st.top() - 'a'] > i) {
                isVisited[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(ch);
            isVisited[ch - 'a'] = true;
        }
        
        s="";
        while(!st.empty())
            s += st.top(), st.pop();
        
        reverse(s.begin(), s.end());
        return s;
    }
};