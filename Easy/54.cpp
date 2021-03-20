class Solution
{
public:
  int maxProfit(vector<int> &v)
  {

    int mx = 0, mn = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] < mn)
        mn = v[i];
      else
        mx = max(mx, v[i] - mn);
    }

    return mx;
  }
};
