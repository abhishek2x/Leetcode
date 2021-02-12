class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        if(s.length() != t.length())
            return false;
        
        for(char ch: s) m[ch]++;
        
        for(char k: t) m[k]--;
        
        for(char ch: s) 
            if(m[ch] != 0)
                return false;
        return true;
    }
};