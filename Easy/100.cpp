class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int mn=nums[0];
        for(int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
            mn = min(mn, nums[i]);
        }
        
        if(mn >= 1) return 1;
        else return 1-mn;
    }
};