class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
    }

    int ans = -1;

    for (auto &i : mp)
    {
      if (i.second == 1)
      {
        ans = i.first;
      }
    }

    return ans;
  }
};

// OR

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      result ^= nums[i];
    }
    return result;
  }
};