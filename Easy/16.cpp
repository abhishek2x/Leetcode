class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> mp1(26, 0), mp2(26, 0);
        int ans=0;
        
        for(char ch: chars){
            mp1[ch - 'a']++;
        }
        
        for(string word: words) {
            
            for(char ch: word){
                mp2[ch - 'a']++;
            }
            
            bool possible = true;
            for(int i=0; i<=25; i++) {
                if(mp2[i] > mp1[i]){
                    possible=false;
                    break;
                }
            }            
            
            if(possible) {
                ans += word.length();
            }

            for(int i=0; i<=25; i++) {
                mp2[i] = 0;
            }
        }
        return ans;
    }
};
