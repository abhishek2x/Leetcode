class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return 1;
        
        // node with maxm incomming edges
        vector<int> incomming(n+1, 0);
        vector<int> outgoing(n+1, 0);
        
        for(auto i: trust) {
            incomming[i[1]]++;
            outgoing[i[0]]++;
        }
        
        for(int i=0; i<=n; i++)
            if(incomming[i]==n-1 && outgoing[i] == 0) return i;
        
        return -1;
    }
};