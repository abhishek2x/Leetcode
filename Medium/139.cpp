class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        
        for(int ele: nums) {
            minH.push(ele);
            if(minH.size() > k) minH.pop();
        }
        
        return minH.top();
    }
};