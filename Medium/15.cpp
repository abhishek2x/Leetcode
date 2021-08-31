#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
		int n = a.size();
		sort(a.begin(), a.end());
        
		for(int i=0; i<n; i++) {
		
        	int e1 = a[i];
			int l=i+1;
			int h = n-1;
		
        	while(l<h) {
				int sum = e1 + a[l] + a[h]; 
				if(sum == 0) cout << e1 << a[l] << a[h] << "\n";
				if(sum < 0) l++;
				else h--;
			}
		}
    }
};