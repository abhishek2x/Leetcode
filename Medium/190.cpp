class Solution {
public:
    
    bool flag;
    void getPermutations(string s, string s2, int idx) {
        if(idx == s.size()) {
            if(s2.find(s) < s2.size()) {
                flag =true;
            }
            return;
        }
        
        if(flag) return;
        
        for(int i=idx; i<s.size(); i++) {
            swap(s[idx], s[i]);
            getPermutations(s, s2, idx+1);
            swap(s[idx], s[i]);
        }
    }
    
    bool checkInclusion(string s1, string s2) {
        flag = false;
        getPermutations(s1, s2, 0);
        return flag;
    }
};