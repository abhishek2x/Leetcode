class Solution {
public:

    int findUnsortedSubarray(vector<int>& nums) {
        int start=0, end=nums.size()-1;
        int mini = INT_MAX, maxa = INT_MIN;
        
        for(int i=1; i<size(nums); i++)
            if(nums[i] < nums[i-1])
                mini = min(mini, nums[i]);
                
        for(int i=size(nums)-2; i>=0; i--)
            if(nums[i] > nums[i+1])
                maxa = max(maxa, nums[i]);
        
        if(maxa == INT_MIN && mini == INT_MAX) return 0;
        
        for(; start < nums.size(); start++)
            if(nums[start] > mini)
                break;
        
        for(; end >= 0; end--)
            if(nums[end] < maxa)
                break;
        
        return end-start+1;
    }
};