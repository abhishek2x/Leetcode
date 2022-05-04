class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int res=0;
        
        for(int it: nums) {
            int target = k-it;
            if(mp[target] > 0) {
                mp[target]--; res++;
            } else {
                mp[it]++;
            }
        }
        
        return res;
    }
}; 