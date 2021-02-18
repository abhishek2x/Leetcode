class Solution
{
public:
  int sumofSqr(int n)
  {
    int a, sum = 0;
    while (n > 0)
    {
      a = n % 10;
      sum += a * a;
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n)
  {
    int slow = n, fast = n;
    do
    {
      slow = sumofSqr(slow);
      fast = sumofSqr(fast);
      fast = sumofSqr(fast);
    } while (slow != fast);
    if (slow == 1)
      return 1;
    else
      return 0;
  }
};
