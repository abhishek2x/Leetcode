class Solution
{
public:
  string LCS(string X, string Y)
  {
    int len = X.length();
    int Mx = INT_MIN;

    int dp[len + 1][len + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < len + 1; i++)
      for (int j = 0; j < len + 1; j++)
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (X[i - 1] == Y[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          Mx = max(Mx, dp[i][j]);
        }
        else
          dp[i][j] = 0;

    string ans = "";
    cout << Mx << "\n";
    int i = len, j = len;

    while (i > 0 && j > 0)
    {
      if (X[i - 1] == Y[j - 1])
      {
        ans += X[i - 1];
        i--;
        j--;
      }
      else if (dp[i - 1][j] > dp[i][j - 1])
        i--;
      else
        j--;

      cout << ans << " " << i << " " << j << "\n";
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  string longestPalindrome(string s)
  {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return LCS(s, s1);
  }
};