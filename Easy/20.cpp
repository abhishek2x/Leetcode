class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    set<int> s;
    for (int i : nums1)
    {
      if (find(nums2.begin(), nums2.end(), i) != nums2.end())
      {
        s.insert(i);
      }
    }
    vector<int> ans;
    for (auto &a : s)
    {
      ans.push_back(a);
    }
    return ans;
  }
};
