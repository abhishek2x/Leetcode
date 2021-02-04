class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        stringstream ss(text); // this is really helpful
        string word;
        vector<string> v;
        
        while (ss >> word)
            v.push_back(word);
        
        vector<string> ans;
        
        for(int i=0; i < v.size()-2; i++) {
            if(v[i]==first && v[i+1] == second){
                ans.push_back(v[i+2]);
            }
        }
        return ans;
    }
};