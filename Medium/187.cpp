class Solution {
public:
    
    void _permute(int index, vector<int>& nums, vector<vector<int>>& res) {
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            _permute(index+1, nums, res);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        _permute(0, nums, res);
        return res;
    }
};