class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int freq[26];
        int window[26];
        
        memset(freq, 0, sizeof(freq));
        memset(window, 0, sizeof(window));
        
        for(char ch: s1) freq[ch-'a']++;
        
        int l=0; 
        int h= s1.size()-1;
        
        for(int i=l; i<=h; i++) window[s2[i] - 'a']++;
        
        while(h < s2.size()) {
            bool flag = true;
            
            for(char ch: s1) {
                if(freq[ch-'a'] != window[ch-'a']) 
                    {flag = false; break;}
            }
            
            if(flag) return true;
            l++;
            h++;
            window[s2[l-1] - 'a']--;
            if(h < s2.size()) window[s2[h] - 'a']++;
        }
        
        return false;
    }
};