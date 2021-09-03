#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();  //row
        int n = grid[0].size(); //col
        int count=0;

        for(int i=0; i<m; i++) {
            // binary search on i'th row
            int indexOfFirstNegative = n;

            int l=0; int r = n-1;
            while(l<=r) {
                int m = (l+r)/2;
                // cout << l << "-" << r << "-" << m << "\n";
                if(grid[i][m] < 0) {
                    indexOfFirstNegative = min(indexOfFirstNegative, m);
                    r = m-1;
                }
                else l = m+1;
            }
            // cout << indexOfFirstNegative << "\n";
            count += n-indexOfFirstNegative;
        }
        return count;
    }
};