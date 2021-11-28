class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suf(n, 1);
        
        pre[0] = nums[0];
        for(int i=1; i<n; i++) pre[i] = nums[i]*pre[i-1];
        
        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) suf[i] *= nums[i] * suf[i+1];
        
        
        nums[0] = suf[1];
        nums[n-1] = pre[n-2];
        
        for(int i=1; i<n-1; i++) {
            nums[i] = pre[i-1] * suf[i+1];
        }
        
        return nums;
    }
};