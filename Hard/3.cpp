class Solution
{
public:
  int largestRectangleArea(vector<int> &a)
  {
    int n = a.size();

    vector<int> left, right;

    // stack<pair<index, value> > s;
    stack<pair<int, int>> s;

    // Computing left limits
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

    // Printing left array
    // for(int i=0; i< left.size(); i++)
    //   cout << left[i] << ", ";

    while (!s.empty())
      s.pop();

    // Computing Right Array

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

    // Printing right array
    // for(int i=0; i<right.size(); i++)
    //   cout << right[i] << ", ";

    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++)
      maxArea = max(maxArea, (right[i] - left[i] - 1) * a[i]);

    return maxArea;
  }
};