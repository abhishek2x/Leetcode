class Solution {
public:
    
    int findParent(int ele, vector<int> &parent) {
        if(ele == parent[ele]) return ele;
        return parent[ele] = findParent(parent[ele], parent);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> parent(n);
        
        for(int i=0; i<n; i++) parent[i] = i;
        
        int groups=n;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isConnected[i][j]) {
                    // union of i and j
                    if(findParent(i, parent) != findParent(j, parent)){
                        parent[findParent(i, parent)] = findParent(j, parent);
                        groups--;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) parent[i] = findParent(i, parent);
        return groups;
    }
};



