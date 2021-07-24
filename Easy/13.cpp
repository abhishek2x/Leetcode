class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> seen;
        for (int a: A) {
            if (seen.count(a))
                return a;
            seen.insert(a);
        }
        return -1;
    }
};
