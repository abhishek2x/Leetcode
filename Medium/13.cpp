#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        vector<string> v(numRows);

		int curr_row=0;
		bool direcDown=true;
		for(char ch: s) {
			if(direcDown){
				v[curr_row].push_back(ch); curr_row++;
			}
			else {
				curr_row--;
                v[curr_row].push_back(ch);
				// for(int i=0; i<numRows; i++) {
				// 	if(i == curr_row)
				// 	else v[i].push_back('\t\t');
				// }
			}
			if(curr_row == 0) {
				direcDown = true;
                curr_row++;
			}
			if(curr_row == numRows) {
				direcDown = false;
                curr_row--;
			}
		}
        
        string ans="";
        for(int i=0; i<numRows; i++) {
            // cout << v[i] << "\n";
            ans += v[i];
        }        
        return ans;
    }
};