class UnionFind {
  
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
    public:
    int count;
    
    UnionFind(vector<vector<int>>& stones) {
        for(auto stone: stones) {
            int row = -(stone[0]+1);
            int col = +(stone[1]+1);
            parent[row] = row;
            parent[col] = col;
        }
        count = parent.size();
    }
    
    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int xGroup = find(x);
        int yGroup = find(y);
        
        if(xGroup == yGroup) return;
        count--;
        
        if(rank[xGroup] < rank[yGroup]) parent[xGroup] = yGroup;
        else if(rank[xGroup] > rank[yGroup]) parent[yGroup] = xGroup;
        else {
            parent[xGroup] = yGroup;
            yGroup++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        UnionFind uf(stones);
        
        for(auto stone: stones) {
            int row = -(stone[0]+1);
            int col = +(stone[1]+1);
            uf.unite(row, col);
        }
        // cout << uf.count << " ";
        return stones.size() - uf.count;
    }
};