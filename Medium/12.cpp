class Solution {
public:
    
    int max(int a, int b) {
        return a ? a>b : b;
    }
    
    int lengthOfLongestSubstring(string s) {
        int l=0;
        set<int> st;
        int dis=INT_MIN;
        
        for(int r=0; r<s.length(); r++) {
            
            while(st.find(s[r]) != st.end()) {
                // remove s[r] from set ans inc l
                auto f = st.find(s[r]);
                if(f != st.end()) st.erase(f);
                l++;
            }
            
            dis = max(dis, r-l+1);
            st.insert(s[r]);
        }
        return dis;
    }
};