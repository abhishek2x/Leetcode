// ** Optimised 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(), 0);
        int i, j;
        
        for(i=t.size()-1; i>=0; i--) {
            for(j=i+1; j<t.size() && t[j] <= t[i]; ) {
                if(res[j] > 0) j += res[j];
                else j = t.size();
            }
            if(j<t.size()) res[i] = j-i;
        }
        
        return res;
    }
};


// ! TLE

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res;
        
        for(int i=0; i<t.size(); i++) {
            int ans=0;
            for(int j=i+1; j<t.size(); j++) {
                if(t[j] > t[i]) {
                    ans = j-i;
                    break;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};