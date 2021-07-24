#include <bits/stdc++.h>
using namespace std;


class Solution {

public:
    int IndexOfEntryInLeave(int ele, vector<int> a) {
        for(int i=0; i<a.size(); i++) {
            if(a[i] == ele) return i; 
        }
        return -1;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int targetVal = times[targetFriend][0];
        sort(times.begin(), times.end());

        int n = times.size();
        vector<int> entry(n, 0);
        vector<int> leave(n, 0);

        for(int i=0; i<n; i++) {
            entry[i] = times[i][0];
            leave[i] = times[i][1];
        }

        int i=0, pos=0;
        while(true) {
            if(entry[pos] == targetVal) break;
            if(find(leave.begin(), leave.end(), entry[pos]) != leave.end()) {
                if(entry[pos] == targetVal) 
                    return IndexOfEntryInLeave(entry[pos], entry);
            }
            else i++;
            pos++;
        }

        return i;
    }
};