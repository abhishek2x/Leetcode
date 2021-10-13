class Solution {
public:
    
    bool dfs(int src, unordered_map<int, vector<int>>& g, vector<int>& vis, vector<int>& color, int c) {
        vis[src] = 1;
        color[src] = c;
        
        for(int it: g[src]) {
            if(!vis[it]) {
               if(!dfs(it, g, vis, color, ~c)) return false;
            } 
            else if(color[it] == color[src]) return false;
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> g;
        vector<int> vis(n+1, 0);
        vector<int> color(n+1, -1);
        
        for(auto it: dislikes) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        for(int i=1; i<n; i++) 
            if(!vis[i])
                if(!dfs(i, g, vis, color, 1)) return false;
        
        return true;
    }
};