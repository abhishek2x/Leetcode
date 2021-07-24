class Solution
{
public:
  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }

public:
  int largestHisto(vector<int> a, int n)
  {
    vector<int> left, right;
    //   pair<index, value>
    stack<pair<int, int>> s;

    // compute left
    for (int i = 0; i < n; i++)
    {
      while (!s.empty() && s.top().second >= a[i])
        s.pop();

      if (s.empty())
        left.push_back(-1);
      else
        left.push_back(s.top().first);

      s.push({i, a[i]});
    }

    while (!s.empty())
      s.pop();

    // compute right
    for (int i = n - 1; i >= 0; i--)
    {
      while (!s.empty() && s.top().second >= a[i])
        s.pop();

      if (s.empty())
        right.push_back(n);
      else
        right.push_back(s.top().first);

      s.push({i, a[i]});
    }

    reverse(right.begin(), right.end());

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
      ans = max(ans, (right[i] - left[i] - 1) * a[i]);

    //   cout << ans << "\n";
    return ans;
  }

public:
  int maximalRectangle(vector<vector<char>> &M)
  {

    int n = M.size();
    if (n == 0)
      return 0;
    int m = M[0].size();
    if (m == 0)
      return 0;

    vector<int> a(m, 0);
    int maxRect = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (M[i][j] != '0')
          a[j] += 1;
        else
          a[j] = 0;
      }
      maxRect = max(maxRect, largestHisto(a, m));
    }
    return maxRect;
  }
};