class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        
        res.push_back(v[0]);
        
        for(int i=1; i<v.size(); i++) {
            int start = v[i][0];
            int end = v[i][1];
            
            int lastEnd = res[res.size()-1][1];
            
            if(lastEnd >= start) //overlapping
                res[res.size()-1][1] = max(res[res.size()-1][1], end);
            else res.push_back({start, end});
        }
        
        return res;
    }
};