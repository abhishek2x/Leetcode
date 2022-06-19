class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int lastDestination = -1;
        for(auto it: trips) lastDestination = max(lastDestination, it[2]);
        lastDestination++;
        
        vector<int> way(lastDestination, 0);
        for(auto it: trips) {
            way[it[1]] += it[0];
            way[it[2]] -= it[0];
        }
        
        int max_cap = way[0];
        for(int i=1; i < lastDestination; i++) {
            way[i] += way[i-1];
            max_cap = max(max_cap, way[i]);
        }
        
        return max_cap <= capacity;
    }
};