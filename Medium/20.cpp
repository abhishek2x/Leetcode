#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void generator(string str, int o, int c) {
        if(o == 0 && c == 0) {
            ans.push_back(str);
            return;
        }
        if(o >= c) {
            if(o>0) generator(str+"(", o-1, c);
        } 
        if (c > o){
            if(c>0) generator(str+")", o, c-1);
            if(o>0) generator(str+"(", o-1, c);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        ans.clear();
        generator("", n, n);
        return ans;
    }
};