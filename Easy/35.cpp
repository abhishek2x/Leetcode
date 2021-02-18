class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> umap;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
      int toFind = target - nums[i];

      if (umap.find(toFind) != umap.end())
      {
        v.push_back(umap[toFind]);
        v.push_back(i);
        return v;
      }
      umap[nums[i]] = i;
    }
    return v;
  }
};
