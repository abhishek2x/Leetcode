#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans=0;

        for(string str: operations) {
            if(str[1] == '+')
                ans++;
            else ans--;
        }
        return ans;
    }
};