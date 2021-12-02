class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        int dp[len];
        
        if(s[0] == '0')
            dp[0] = 0;
        else dp[0] = 1;
        
        for(int i=1; i<len; i++) {
            char l2 = s[i];
            char l1 = s[i-1];
            
            if(l1 == '0' && l2 == '0') {
                dp[i] = 0;
            } else if(l1 == '0' && l2 != '0') {
                dp[i] = dp[i-1];
            } else if(l1 != '0' && l2 == '0') {
                if(l1 == '1' || l1 == '2')
                    dp[i] = (i>=2 ? dp[i-2] : 1);
                else dp[i] = 0;
            } else {
                string two = s.substr(i-1, 2);
                int num = std::stod(two);
                if(num <= 26)
                    dp[i] = dp[i-1] + (i>=2 ? dp[i-2] : 1);
                else dp[i] = dp[i-1];
            }
        }
        
        return dp[len-1];
    }
};