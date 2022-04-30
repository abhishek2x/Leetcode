class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res=0;
        for(auto word: words) {
            string tempStr = s.substr(0, word.size());
            // cout << word << " " << tempStr << "\n";
            if(tempStr == word) res++;
        }
        return res;
    }
};