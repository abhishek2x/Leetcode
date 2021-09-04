#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int start=0;
        int maxOnes=0;
        int zeroCnt=0;

        for(int end=0; end<a.size(); end++) {
            if(a[end] == 0) zeroCnt++;
            if(zeroCnt > k) {
                if(a[start] == 0) zeroCnt--;
                start++;
            }
            maxOnes = max(maxOnes, end-start+1);
        }
        return maxOnes;
    }
};