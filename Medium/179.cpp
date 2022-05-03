class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(begin(nums), end(nums));
        
        int start=-1, end=-1;
        for(int i=0; i<size(temp); i++) {
            if(temp[i] != nums[i]) {
                start = i; break;
            }
        }
        
        for(int i=size(temp)-1; i>=0; i--) {
            if(temp[i] != nums[i]) {
                end = i; break;
            }
        }
        if(start == -1 && end == -1) return 0;
        return end-start+1;
    }
};