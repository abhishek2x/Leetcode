class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> res(nums1.size(), -1);
        
        for(int ele: nums2) {
            while(!st.empty() && st.top() < ele) {
                mp[st.top()] = ele;
                st.pop();
            }
            st.push(ele);
        }
        
        for(int i=0; i<nums1.size(); i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                res[i] = mp[nums1[i]];
            }
        }
        return res;
    }
};