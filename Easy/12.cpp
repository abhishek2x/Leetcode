class Solution
{
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums)
  {
    vector<int> ans, v;
    for (int i = 0; i < nums.size(); i++)
    {
      v.push_back(nums[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < nums.size(); i++)
    {
      auto it = lower_bound(v.begin(), v.end(), nums[i]);
      int num = distance(v.begin(), it);
      // cout<<num<<endl;
      ans.push_back(num);
    }
    return ans;
  }
};
