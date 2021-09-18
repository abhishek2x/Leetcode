#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(int node, vector<int> &parent) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node], parent); 
    }
    
    bool unite(int n1, int n2, vector<int> &parent) {
        n1 = find(n1, parent);
        n2 = find(n2, parent);

        if(n1 == n2) return false;
        return parent[n1] = n2;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        
        vector<int> parent(e.size()+1);
        for(int i=1; i<=e.size(); i++) parent[i] = i;

        for(int i=0; i<e.size(); i++) {
            int u = e[i][0];
            int v = e[i][1];

            if(!unite(u, v, parent)) return e[i];
        }
        return {};
    }
};