class Solution
{
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
  {
    unordered_map<string, int> umap;
    for (int i = 0; i < list1.size(); i++)
    {
      umap[list1[i]] = i;
    }

    int sMax = INT_MAX;
    vector<string> s;

    for (int i = 0; i < list2.size(); i++)
    {
      if (umap.find(list2[i]) != umap.end())
      {

        int sum = umap[list2[i]] + i;
        if (sum < sMax)
        {
          s.clear();
        }
        if (sum <= sMax)
        {
          s.push_back(list2[i]);
          sMax = sum;
        }
      }
    }
    return s;
  }
};