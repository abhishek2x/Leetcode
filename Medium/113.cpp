class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // store tuple in heap with smallest sum on top
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty() && k) {
            auto ele = pq.top();
            vector<int> temp = { get<1>(ele), get<2>(ele) };
            res.push_back(temp);
            pq.pop(); k--;
        }
        
        return res;
    }
};