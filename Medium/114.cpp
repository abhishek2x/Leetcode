class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int >>, greater<tuple<int, int, int>>> pq;
        
        for(int i = 0; i < n; i++) 
            pq.push({nums1[i] + nums2[0], i, 0});
        
        while(k-- and pq.size()) {
            auto [sum, i, j] = pq.top(); pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            
            if(j < m - 1)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        
        return ans;
    }
};
