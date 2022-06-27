class Solution {
public:
    string lastSubstring(string s) {
        char mx=s[0];
        int mx_index=0;
        
        for(int i=1; i<s.size(); i++) {
            if(s[i] > mx) {
                mx = s[i];
                mx_index = i;
            }
            else if(s[i] == mx) {
                int j=1;
                while(s[i+j] == s[mx_index+j] && mx_index+j < i) j++;
                if(s[i+j] > s[mx_index+j]) mx_index = i;
                i = i+j-1;
            }
        }
        return s.substr(mx_index);
    }
};

// "cacacb"