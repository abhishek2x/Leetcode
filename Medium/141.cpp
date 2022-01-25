class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i: nums) mp[i]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        
        for(auto ele: mp) {
            minH.push({ele.second, ele.first});    
            if(minH.size() > k) minH.pop();
        }
 
        nums.clear();
        while(minH.size() > 0) {
            nums.push_back(minH.top().second);
            minH.pop();
        }
        return nums;
    }
};