#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        set<vector<int>>ans;
		int n = a.size();
		sort(a.begin(), a.end());
        
		for(int i=0; i<n; i++) {
		
        	int e1 = a[i];
			int l=i+1;
			int h = n-1;
            
        	while(l<h) {
				int sum = e1 + a[l] + a[h]; 
				if(sum == 0) {
                    ans.insert({a[i],a[l],a[h]});
                    l++;
                }
				if(sum < 0) l++;
				else h--;
			}
		}
        vector<vector<int>>finalans;
        set<vector<int>>::iterator it=ans.begin();
         
        while(it!=ans.end()){
            finalans.push_back(*it);
            it++;
        }
        
        return finalans;
    }
};