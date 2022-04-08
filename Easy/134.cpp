class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int freq=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val) {
                nums[i] = 50;
                freq++;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size()-freq;
    }
};