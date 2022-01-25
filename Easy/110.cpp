class Solution {
public:
    
    static bool comp(pair<int, int> i, pair<int, int> j) {
        return i.second < j.second;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int, int>> v;
        for(int i=0; i<nums.size(); i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        sort(v.begin(), v.begin()+k, comp);
        
        vector<int> res;
        for(int i=0; i<k; i++) res.push_back(v[i].first);
        
        return res;
    }
};