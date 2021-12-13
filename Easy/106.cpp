class Solution {
public:
    int maxPower(string s) {
        int st=0, ed=0, res=0;
        char ch = '\0';
        
        for(int i=0;i<size(s); i++) {
            if(s[i] != ch) {
                st = i;
                ed = i;
                ch = s[i];
            } else {
                ed++;
            }
            res = max(res, ed-st+1);
            // cout << s[i] << " - " << ch << ": " << st << " " << ed << "\n";
        }
        return res;
    }
};