#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = a.size();
        sort(a.begin(), a.end());

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                int required = target - a[i] - a[j];
                
                int low=j+1;
                int high=n-1;

                while(low<high) {
                    int sum = a[low] + a[high];
                    if(sum == required) {
                        st.insert({a[i], a[j], a[low], a[high]});
                        low++;
                    }
                    if(sum < required) low++;
                    else high--;
                }
            }
        }
        
        for(auto vec: st) ans.push_back(vec);
        
        return ans;
    }
};