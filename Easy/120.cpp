class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDis=INT_MAX;
        int minIdx = -1;
        
        for(int i=0; i<points.size(); i++) {
            auto point = points[i];
            if(point[0] != x and point[1] != y) continue;
            
            int dis = abs(point[0]-x) + abs(point[1]-y);
            if(dis < minDis) {
                minDis = dis;
                minIdx = i;
            }
        }
        
        return minIdx;
    }
};