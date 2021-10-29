class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int freq[] = {0, 0, 0};
        for(int ele: nums) freq[ele]++;
        
        for(int i=0; i<n; i++) {
            if(freq[0] > 0) {nums[i] = 0; freq[0]--;}
            else if(freq[1] > 0) {nums[i] = 1; freq[1]--;}
            else if(freq[2] > 0) {nums[i] = 2; freq[2]--;}
        }
    }
};