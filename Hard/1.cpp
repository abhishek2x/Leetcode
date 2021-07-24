class Solution
{
public:
  string shortestCommonSupersequence(string str1, string str2)
  {
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    int i, j;

    for (i = 0; i <= m; i++)
      for (j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (str1[i - 1] == str2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }

    // cout << (m+n) - dp[m][n];
    string lcs = "", res = "";
    i = m, j = n;

    while (i > 0 && j > 0)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        lcs += str1[i - 1];
        i--;
        j--;
      }
      else if (dp[i][j - 1] > dp[i - 1][j])
        j--;
      else
        i--;
    }

    reverse(lcs.begin(), lcs.end());
    i = 0;
    j = 0;

    for (char c : lcs)
    {
      while (str1[i] != c)
        res += str1[i++];
      while (str2[j] != c)
        res += str2[j++];
      res += c, i++, j++;
    }

    return res + str1.substr(i) + str2.substr(j);
  }
};