class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int p1 = nums[1];
        int pp1 = 0;
        
        for(int i=2; i<nums.size(); i++) {
            int take = nums[i] + pp1;
            int notTake = 0 + p1;
            
            pp1 = p1;
            p1 = max(take, notTake);
        }
        
        int p2 = nums[0];
        int pp2 = 0;
        
        for(int i=1; i<nums.size()-1; i++) {
            int take = nums[i] + pp2;
            int notTake = 0 + p2;
            
            pp2 = p2;
            p2 = max(take, notTake);
        }
        
        return max(p1, p2);
    }
};