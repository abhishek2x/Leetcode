class Solution
{
public:
  vector<int> distributeCandies(int candies, int num_people)
  {
    vector<int> ar(num_people, 0);
    int res = 0;
    while (candies > 0)
    {
      ar[res % ar.size()] += min(res + 1, candies);
      candies -= res + 1;
      res++;
    }
    return ar;
  }
};