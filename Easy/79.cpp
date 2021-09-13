class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int, int> freq;
        
        for(int no: nums) freq[no]++;
        for(auto it: freq) if(it.second>1) return true;
        
        return false;
    }
};