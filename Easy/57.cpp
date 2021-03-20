class Solution
{
public:
  int climbStairs(int n)
  {
    int dp[50];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
      if (i < 3)
        dp[i] = i;
      else
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
