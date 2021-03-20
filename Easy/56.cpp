class Solution
{
public:
  int dp[105][10005];
  int sub(string s, string t, int m, int n)
  {

    for (int i = 0; i < m + 1; i++)
      for (int j = 0; j < n + 1; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (s[i - 1] == t[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    return dp[m][n];
  }

  bool isSubsequence(string s, string t)
  {
    memset(dp, -1, sizeof(dp));
    int len = sub(s, t, s.length(), t.length());
    // cout << len;
    return len == s.length();
  }
}