class Solution {
public:
    
    void dfs(int src, vector<int> &vis, vector<vector<int>>& rooms) {
        vis[src] = 1;
        cout << src << " ";
        for(auto i: rooms[src])
            if(!vis[i])
                dfs(i, vis, rooms);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<int> vis(size, 0);
        
        dfs(0, vis, rooms);
        
        for(int i: vis) if(!i) return false;
        return true;
    }
};