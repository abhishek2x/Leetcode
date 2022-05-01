class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long leftSum=0, rightSum=0;
        
        for(auto it: nums) rightSum += it;
        
        int mini=INT_MAX, index=0;
        
        for(int i=0; i<nums.size(); i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            
            long long ans1, ans2;
            ans1 = leftSum / (i+1);
            ans2 = i<nums.size()-1 ? rightSum / (nums.size() - i - 1) : 0;
            
            if(abs(ans1-ans2) < mini) {
                mini = abs(ans1-ans2);
                index = i;
            }
        }
        return index;
    }
};
