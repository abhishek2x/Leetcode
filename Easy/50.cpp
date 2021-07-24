class Solution
{
public:
  bool backspaceCompare(string S, string T)
  {
    string s1 = "", s2 = "";
    for (int i = 0; i < S.length(); i++)
    {
      if (S[i] != '#')
        s1 += S[i];
      else if (s1.length() > 0)
        s1 = s1.substr(0, s1.length() - 1);
    }
    for (int j = 0; j < T.length(); j++)
    {
      if (T[j] != '#')
        s2 += T[j];
      else if (s2.length() > 0)
        s2 = s2.substr(0, s2.length() - 1);
    }
    cout << s2 << "\t" << s1;
    return s1 == s2;
  }
};