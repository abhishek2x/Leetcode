class Solution {
public:
    vector<int> color;
    vector<int> vis;
    
    bool dfs(int src, vector<vector<int>>& graph, int c) {
        vis[src] = 1;
        color[src] = c;
        
        for(int it: graph[src]) {
            if(!vis[it]) {
                if(!dfs(it, graph, ~c)) 
                    return false;
            }
            else if(color[src] == color[it])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        color.resize(n, -1);
        vis.resize(n, 0);
        
        for(int i=0; i<n; i++) 
            if(!vis[i])
                if(!dfs(i, graph, 1)) 
                    return false;
        
        return true;
    }
};