
// ** Complexity: O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        for(int i=0; i<size(v); i++) {
            if(newInterval[1] < v[i][0]) {
                // before current interval
                res.push_back(newInterval);
                for(int j=i; j<size(v); j++) res.push_back(v[j]);
                return res;
            } else if(newInterval[0] > v[i][1]) {
                // after current interval
                res.push_back(v[i]);
            } else {
                // merge
                newInterval[0] = min(newInterval[0], v[i][0]);
                newInterval[1] = max(newInterval[1], v[i][1]);
            }
        }
        
        res.push_back(newInterval);
        return res;
    }
};



// ** Complexity: O(nlogn)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        // Variation of merge intervals
        
        v.push_back(newInterval); // converted to merge intervals
        sort(v.begin(), v.end());
    
        vector<vector<int>> res;
        res.push_back(v[0]);
        
        for(int i=1; i<size(v); i++) {
            int lastEnd = res[res.size()-1][1];
            int start = v[i][0];
            int end = v[i][1];
            
            if(lastEnd >= start) {
                res[res.size()-1][1] = max(res[res.size()-1][1], end);
            } else res.push_back(v[i]);
        }
        
        return res;
    }
};


