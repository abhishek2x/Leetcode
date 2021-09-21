class UnionFind {
  
    unordered_map<char, char> parent;
    
    public:
        
    UnionFind(vector<string>& equations) {
        for(auto eq: equations) {
            char a = eq[0];
            char b = eq[3];
            parent[a] = a;
            parent[b] = b;
        }
    }
    
    char find(char a) {
        if(a != parent[a]) return parent[a] = find(parent[a]);
        else return parent[a];
    }
    
    bool unite(char a, char b, char symbol) {
        char aGrp = find(a);
        char bGrp = find(b);
        
        if(symbol == '=')
            parent[aGrp] = bGrp;
        else if((aGrp == bGrp && a != b) || a==b)
            return false;
        
        return true;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(equations);
        
        // bring all == at beginning
        vector<string> eqs;
        for(auto e: equations) 
            if(e[1] == '=')
                eqs.push_back(e);
        
        for(auto e: equations) 
            if(e[1] == '!')
                eqs.push_back(e);
        
        for(auto eq: eqs) {
            char a = eq[0];
            char b = eq[3];
            char sym = eq[1];
            bool check = uf.unite(a, b, sym);
            if(!check) return false;
        }   
        return true;
    }
};