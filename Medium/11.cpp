#include <bits/stdc++.h>

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int count=1;
        
        while(getline(ss, curr, ',')) {
            count--;
            if(count < 0) return false;
            if(curr != "#") count+=2;
        }
        return count == 0;
    }
};