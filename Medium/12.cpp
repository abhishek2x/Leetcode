class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        
        int l=0, r=0;
        set<char> st;
        int dis=0;
        
        while(r<n) {
            char ch = s[r];
            while(st.count(ch)) {
                st.erase(s[l]);
                l++;
            }
            
            st.insert(ch);
            dis = max(dis, r-l+1);
            r++;
        }
        return dis;
    }
};