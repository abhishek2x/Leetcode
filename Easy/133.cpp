class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest=strs[0];
        for(string str: strs) {
            int len = min(size(longest), size(str)) - 1;
            string temp="";
            
            for(int i=0; i<=len; i++) {
                if(str[i] == longest[i])
                    temp += str[i];
                else break;
            }
            longest = temp;
        }
        return longest;
    }
};