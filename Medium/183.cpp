class Solution {
public:
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string s1, string s2) {
            return s1.size() < s2.size();
        });
        
        int res = 0;
        unordered_map<string, int> mp;
        
        for(string it: words) {
            mp[it] = 1;
            
            for(int i=0; i<size(it); i++) {
                string tStr = it.substr(0, i) + it.substr(i+1);
                mp[it] = max(mp[it], mp[tStr]+1);
                res = max(res, mp[it]);
            }
        }
        return res;
    }
};