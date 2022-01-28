class Solution {
public:
    
    static int comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        
        int prevEnd = points[0][1];
        int ans=1;
        
        for(int i=0; i<points.size(); i++){
            if(points[i][0] > prevEnd) {
                ans++;
                prevEnd = points[i][1];
            }
        }
        return ans;
    }
};