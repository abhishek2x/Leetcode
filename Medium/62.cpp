class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int pAns = 1;
        int ppAns = 1;
        
        for(int i=1; i<s.length(); i++) {
            
            int d = s[i]-'0';
            int dd = (s[i-1]-'0')*10 + d;
            int Ans=0;
            
            if(d > 0) Ans += pAns;
            if(dd >= 10 && dd <= 26) Ans += ppAns;
            
            ppAns = pAns;
            pAns = Ans;
        }
        return pAns;
    }
};