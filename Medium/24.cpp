#include <bits.stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        
        for(int i=0; i<n; i++) {
            if(a[i] == 1) {
                int c=1;
                for(int j=i+1; j<n; j++) {
                    if(a[j] == 1) c++;
                    else {
                        if(k) k--;c++;
                    }
                }
            }
        }
    }
};