class Solution
{
public:
  bool divisorGame(int N)
  {
    bool alice = false;
    if (N == 1)
      return false;
    while (N > 1)
    {
      // cout << N << " ";
      bool found = false;
      int d;
      for (int i = 1; i <= N; i++)
      {
        if (N % i == 0)
        {
          found = true;
          d = i;
          break;
        }
        if (found)
          break;
      }
      if (found)
      {
        N -= d;
        alice = !alice;
      }
    }
    return alice;
  }
};