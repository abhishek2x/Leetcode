class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(char ch: s){
            mp[ch]++;
        }
        
        int Oods=0;
        
        for(auto i: mp) {
            if(i.second & 1) {
                Oods++;
            } 
        }
        return s.length() - Oods + (Oods > 0);
    }
};

Or

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c='A'; c<='z'; c++)
            odds += count(s.begin(), s.end(), c) & 1;
        return s.size() - odds + (odds > 0);
    }
};