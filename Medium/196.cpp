class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);
        
        for(int i=nums.size()*2-1; i>=0; i--) {
            while(!st.empty() and st.top() <= nums[i%n]) st.pop();
            
            if(i < n) {
                if(st.empty()) res[i] = -1;
                else res[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        
        return res;
    }
};