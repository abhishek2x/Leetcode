class Solution
{
public:
  int totalMoney(int n)
  {

    int iSum = 21;
    int weeks = n / 7;
    int days = n % 7;
    int ans = 0;

    for (int i = 1; i <= weeks; i++)
    {
      ans += iSum + (i * 7);
    }

    for (int i = 1; i <= days; i++)
    {
      ans += weeks + i;
    }

    return ans;
  };
};