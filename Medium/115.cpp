class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minH;
        
        unordered_map<string, int> mp;
        
        for(string wd: words) mp[wd]++;
        
        for(auto it: mp) {
            minH.push({-it.second, it.first});
            // if(minH.size() > k) minH.pop();
        }
        
        vector<string> res;
        
        while(k--) {
            res.push_back(minH.top().second); 
            minH.pop();
        }
        
        return res;
    }
};