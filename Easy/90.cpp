class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        string res="";
        
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;
        
        for(int i=0; i<arr.size(); i++) {
            if(mp[arr[i]] == 1){
                if(k == 1) res = arr[i];
                k--;
            }
        }
        return res;
    }
};