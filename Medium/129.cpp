
class Solution {
public: 
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        
        int i=0, j=0;
        while(i<f.size() && j<s.size()) {
            int u = max(f[i][0], s[j][0]);
            int v = min(f[i][1], s[j][1]);
            if( u <= v ) res.push_back({u, v});
            if(f[i][1] < s[j][1]) i++;
            else j++;
        }
        
        return res;
    }
};

// ! TLE
// class Solution {
// public: 
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
//         vector<vector<int>> res;
        
//         for(auto it1: f) {
//             for(auto it2: s) {
//                 int ff = it1[0];
//                 int fs = it1[1];
//                 int sf = it2[0];
//                 int ss = it2[1];
                
//                 if(fs >= sf && ff <= ss) {
//                     vector<int> temp(2);
//                     temp[0] = max(ff, sf);
//                     temp[1] = min(fs, ss);
//                     res.push_back(temp);
//                 }
//             }
//         }
        
//         return res;
//     }
// };