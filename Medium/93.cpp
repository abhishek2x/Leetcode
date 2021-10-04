// BFS

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it: times) 
            adj[it[0]].push_back({it[1], it[2]});
        
        vector<int> dist(n+1, INT_MAX);
        queue<int> q;
        
        q.push(k);
        dist[k] = 0;
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            for(auto next: adj[p]) {
                if(dist[p] + next.second < dist[next.first]) {
                    dist[next.first] = dist[p] + next.second;
                    q.push(next.first);
                }
            }
        }
        int ans=0;
        
        for(int i=1; i<=n; i++)
            if(dist[i] == INT_MAX) return -1;
            else ans = max(ans, dist[i]);
        
        return ans;
        
    }
};

// Dijkstra Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it: times) 
            adj[it[0]].push_back({it[1], it[2]});
        
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
        dist[k] = 0;
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            for(auto next: adj[p.second]) {
                if(p.first + next.second < dist[next.first]) {
                    dist[next.first] = p.first + next.second;
                    pq.push({dist[next.first], next.first});
                }
            }
        }
        int ans=0;
        
        for(int i=1; i<=n; i++)
            if(dist[i] == INT_MAX) return -1;
            else ans = max(ans, dist[i]);
        
        return ans;
        
    }
};

// Bellman-Ford Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        
        // relax n-1 times
        
        for(int i=0; i<n-1; i++) {
            bool flag = false;
            
            for(auto node: times) {
                int src = node[0];
                int des = node[1];
                int time = node[2];
                
                if(dist[src] != INT_MAX && dist[src]+time < dist[des]) {
                    dist[des] = dist[src] + time;
                    flag = true;
                }
            }
            if(flag == false) break;
        }
        
        int ans = 0; 
        
        for(int i=1; i<n+1; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};