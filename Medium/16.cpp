#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& a, int target) {
		sort(a.begin(), a.end());
        int n = a.size();
        int ans=0;
        
        int mn=INT_MAX;
        int nt;

        for(int i=0; i<n; i++) {
            int j=i+1;
            int k=n-1;
            while(j<k) {
                int sum = a[i] + a[j] + a[k];
                if(abs(sum-target) < mn) {
                    mn = abs(sum-target);
                    nt = sum;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return nt;
	}
};