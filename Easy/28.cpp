class Solution {
public:
    
    bool isEligible(string ip, string op) {
        // check if op is in ip
        vector<int> v(26, 0);
        for(char ch: ip) v[ch-'a']++;
        for(char ch: op){
            if(v[ch-'a'] == 0) return false;
            v[ch-'a']--;
        }
        return true;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string licensePlate2="";
        
        for(char ch: licensePlate){
            if(ch >= 'a' && ch <= 'z') licensePlate2 += ch;
            else if(ch >= 'A' && ch <='Z')  licensePlate2 += tolower(ch);
        }
        
        int shortest = INT_MAX;
        string ans;
        
        for(string word: words) {
            if(isEligible(word, licensePlate2)) {
                if(word.length() < shortest) {
                    shortest = word.length();
                    ans = word;
                }
            }
        }        
        return ans;
    }
};