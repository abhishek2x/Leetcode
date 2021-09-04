#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isLand(vector<vector<int>>& land, int i, int j) {
        int row = land.size();
        int col = land[0].size();
        if(i>=row || j>=col || i<0 || j<0) return true;
        return land[i][j];
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(!isLand(land, i, j)) continue;
                else {
                    land[i][j] = 0;
                    int t1=i, t2=j;
                    while((isLand(land, t1+1, t2) || isLand(land, t1, t2+1))){
                        if(isLand(land, t1, t2+1)){t2++;}
                        else if(isLand(land, t1+1, t2)){t1++;}
                    }
                    ans.push_back({i, j, t1, t2});
                }
            }
        }
        return ans;
    }
};