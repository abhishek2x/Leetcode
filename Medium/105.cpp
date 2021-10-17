
// Efficient
void wiggleSort(int[] nums)
{
    for (int i = 0; i < nums.length - 1; i++)
    {
        if ((i % 2 == 0) == (nums[i] > nums[i + 1]))
        {
            swap(nums, i, i + 1);
        }
    }
}

// Trivial
// Complexity: O(nlogn)
#inculde < bits / stdc++.h>
Using namespace std;

Class Solution
{
Public:
    vector<int> wiggleSort(vector<int> n)
    {
        vector<int> ans;

        sort(n.begin(), b.end());
        Int i = 0, k = n.size() - 1;

        while (i < j)
        {
            ans.push_back(n[i++]);
            ans.push_back(n[j--]);
        }
        if (n % 2)
            ans.push_back(n[i]);

        Return ans;
    }
