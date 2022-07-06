class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int peek = 1, valley = 1;
        
        for(int i=1; i<v.size(); i++) {
            if(v[i] > v[i-1]) valley = peek + 1;
            else if(v[i] < v[i-1]) peek = valley + 1;
        }
        
        return max(peek, valley);
    }
};