class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // k largest element
        // heap?
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int i: nums) {
            minH.push(i);
            if(minH.size() > k) minH.pop();
        }
        
        vector<int> res;
        while(minH.size() > 0) {
            res.push_back(minH.top());
            minH.pop();
        }
        return res;
    }
};