class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int res=0, prevEnd=v[0][1];
        
        for(int i=1; i<v.size(); i++) {
            int start = v[i][0];
            int end = v[i][1];
            
            if(start >= prevEnd) {
                prevEnd = end;
            }
            else {
                prevEnd = min(prevEnd, end);
                res++;
            }
        }
        return res;
    }
};