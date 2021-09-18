class Solution {
public:
    
    int ans=0;
    
    void dfs(int src, int parent, set<pair<int, int>>& st, vector<int>& vis, unordered_map<int, vector<int>>& mp) {

        vis[src] = 1;
        
        auto p = make_pair(parent, src);
        if(st.find(p) != st.end()) {        
            cout << src << " " << parent << "\n";
            ans++;
        }

        for(auto it: mp[src])
            if(!vis[it])
                dfs(it, src, st, vis, mp);
    }
    
    int minReorder(int n, vector<vector<int>>& conn) {
        
        ans=0;        
        unordered_map<int, vector<int>> mp;
        set<pair<int, int>> st;
        vector<int> vis(n, 0);
        
        for(auto it: conn) {
            int u = it[0];
            int v = it[1];
            // cout << u << " " << v << "\n";
            mp[u].push_back(v);
            mp[v].push_back(u);

            st.insert({u, v});
        }
        
        // for(auto it: mp) {
        //     cout << it.first << "=> ";
        //     for(auto ele: it.second) cout << ele << " ";
        //     cout << "\n";
        // }
        
        // for(int i=0; i<n; i++)
        dfs(0, -1, st, vis, mp);
        return ans;
    }
};
