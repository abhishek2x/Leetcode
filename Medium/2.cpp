// Recursive

class Solution
{
public:
  int Cnter(int n, int i)
  {
    if (n == 0)
      return 1;

    int result = 0;
    for (int k = i; k < 5; k++)
    {
      result += Cnter(n - 1, k);
    }
    return result;
  }

  int countVowelStrings(int n)
  {
    return Cnter(n, 0);
  }
};