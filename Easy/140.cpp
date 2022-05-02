class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        
        for(auto it: nums) 
            if(it%2 == 0) 
                even.push_back(it);
        
        for(auto it: nums) 
            if(it%2 == 1) 
                even.push_back(it);
        return even;
    }
};