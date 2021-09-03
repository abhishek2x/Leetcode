#include <bits/stdc++.h>
using namespace std;

class Solution {
bool comparefn(pair<int, int> p1, pair<int, int> p2);
vector<int> kWeakestRows(vector<vector<int>>& mat, int k);

public:
    bool comparefn(pair<int, int> p1, pair<int, int> p2) {
        if(p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;

        int row = mat.size();
        int col = mat[0].size();

        for(int i=0; i<row; i++) {
            int getindex=0;
            int low=0, high = col-1;

            while(low <= high) {
                int mid = (low+high)/2;
                if(mat[i][mid] == 1) {
                    getindex = max(getindex, mid);
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            v.push_back(make_pair(i, getindex+1));
        }

        sort(v.begin(), v.end(), comparefn);
        vector<int> ans;

        for(auto ele: v) {
            if(k == 0) break;
            ans.push_back(ele.first);
            k--;
        }
        return ans;
    }
};