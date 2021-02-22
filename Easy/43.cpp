class Solution {
public:
    bitset<10001> visited;
    
    bool ff(vector<int>& nums, int sum, int k, int target, int lb) {
        if (k == 1) return true;
        if (sum == target) return ff(nums, 0, k-1, target, 0);
        if (lb >= nums.size()) return false;
        for (int i=lb; i<nums.size(); i++) {
            if (!visited[i]) {
                if (sum + nums[i] <= target) {
                    visited[i] = true;
                    if (ff(nums, sum + nums[i], k, target, i+1))
                        return true;
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (!nums.size()) return false;
        if (k == 1 && nums.size()) return true;
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return ff(nums, 0, k, sum/k, 0);
    }
};