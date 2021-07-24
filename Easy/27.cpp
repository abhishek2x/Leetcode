class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        for(char ch: s) {
            mp1[ch]++;
        }
        char ans;
        for(char ch: t) {
            if(mp1[ch] == 0)
                ans = ch;
            mp1[ch]--;
        }
        return ans;
    }
};