class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minH;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int n: nums) {
            minH.push(n);
            if(minH.size() > k) minH.pop();
        }
    }
    
    int add(int val) {
        
        minH.push(val);
        if(minH.size() > K) 
            minH.pop();
        
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */