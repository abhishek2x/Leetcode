class Solution
{
public:
  int dp[1001] = {0};
  int getCost(vector<int> &cost, int n)
  {
    if (n < 0)
      return 0;
    if (n == 0 || n == 1)
      return cost[n];

    if (dp[n] != 0)
      return dp[n];

    return dp[n] = cost[n] + min(getCost(cost, n - 1), getCost(cost, n - 2));
  }

  int minCostClimbingStairs(vector<int> &cost)
  {
    return min(getCost(cost, cost.size() - 1), getCost(cost, cost.size() - 2));
  }
};