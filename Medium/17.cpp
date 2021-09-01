using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
	vector<string> ans;
	map<char, string> mp;
    
    void conbination(string digits, int len, string curr_str) {
        if(len == 0) {
            ans.push_back(curr_str);
            return;
        }
        
        string str = mp[digits[len-1]];
        
        for(int i=0; i<str.length(); i++) 
            conbination(digits, len-1, str[i]+curr_str);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        mp.clear();
        ans.clear();
        mp['1'] = "";
		mp['2'] = "abc";
		mp['3'] = "def";
		mp['4'] = "ghi";
		mp['5'] = "jkl";
		mp['6'] = "mno";
		mp['7'] = "pqrs";
		mp['8'] = "tuv";
		mp['9'] = "wxyz";

    	conbination(digits,digits.length(),"");

		return ans;
	}
};