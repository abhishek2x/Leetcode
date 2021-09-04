#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool ok(vector<int>& wt, int mid, int days) {
        int D = 1;
        int sum=0;

        for(int w: wt) {
            if(w > mid) return false;
            sum += w;
            if(sum > mid) {
                D++;
                sum = w;
            }
        }
        return D <= days;
    }

    int shipWithinDays(vector<int>& wt, int days) {
        int low = *min_element(wt.begin(), wt.end());
        int high = accumulate(wt.begin(), wt.end(), 0);

        while(low<high) {
            int mid = low + (high-low)/2;
            if(ok(wt, mid, days)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};