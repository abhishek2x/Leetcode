class Solution
{
public:
  int dp[51][6];

  int Cnter(int n, int i)
  {
    if (n == 0)
      return 1;

    int result = 0;
    if (dp[n][i] != -1)
      result += dp[n][i];
    else
    {
      for (int k = i; k < 5; k++)
      {
        int temp = 0;
        if (dp[n - 1][k] != -1)
          result += dp[n - 1][k];
        else
        {
          dp[n - 1][k] = Cnter(n - 1, k);
          result += dp[n - 1][k];
        }
      }
    }
    return result;
  }

  int countVowelStrings(int n)
  {
    memset(dp, -1, sizeof(dp));
    return Cnter(n, 0);
  }
};