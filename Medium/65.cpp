class Solution {
public:
        
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<int> res;
        
        for(auto i: edges) 
            indegree[i[1]]++;
        
        for(int i=0;i<n; i++) 
            if(!indegree[i]) res.push_back(i);
        
        return res;
    }
};