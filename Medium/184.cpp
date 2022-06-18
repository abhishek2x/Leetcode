class Solution {
public:
    string longestPalindrome(string s) {
        int len, n = s.size();
        bool dp[n][n];
        string res="";
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = true;
                }
                else if (g == 1) {
                    dp[i][j] = s[i] == s[j];
                }
                else if((s[i] == s[j]) and dp[i+1][j-1] == true) {
                    dp[i][j] = true;
                }
                else dp[i][j] = false;
                
                if(dp[i][j] == true) {
                    len = g + 1;
                    res = s.substr(i, len);
                }
            }
        }
        return res;
    }
};