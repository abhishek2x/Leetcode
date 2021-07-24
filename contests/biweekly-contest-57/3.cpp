class Solution
{
public:
    bool areOccurrencesEqual(string str)
    {

        map<char, int> mp;

        for (char ch : str)
        {
            mp[ch]++;
        }

        auto firstEntry = *mp.begin();

        int freq = firstEntry.second;
        int flag = 0;

        for (auto i : mp)
        {
            if (i.second != freq)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};