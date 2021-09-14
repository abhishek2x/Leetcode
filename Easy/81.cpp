class Solution {
public:
    
    
    bool dfs(int src, vector<int> &vis, unordered_map<int,vector<int>>& graph, int end) {
        vis[src] = 1;
        if(src == end) return true;
            
        for(auto it: graph[src]) {
            if(!vis[it])
                if(dfs(it, vis, graph, end)) return true;    
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 

        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n, 0);
        
        if(dfs(start, vis, graph, end)) 
            return true;
        
        return false;
    }
};