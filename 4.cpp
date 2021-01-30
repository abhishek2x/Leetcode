class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> arr;
        int inc = 0;
        int dec = S.length();
        
        
        for(int i=0; i < S.length(); i++){
            if(S[i] == 'I')
                arr.push_back(inc++);
            else if (S[i] == 'D')
                arr.push_back(dec--);
        }
        
        if(S[S.length()-1] == 'I')
            arr.push_back(inc);
        else arr.push_back(dec);
        return arr;
    }
};