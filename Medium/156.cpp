class Solution {
public:
    int calculate(string s) {
        s += "+";
        stack<int> st;
        
        long long int cur=0, ans=0;
        char prev_sign = '+';
        
        for(char ch: s) {
            if(isdigit(ch)) 
                cur = cur*10 + (ch-'0');
            
            else if(ch == '+' || ch == '/' || ch == '*' || ch == '-') {
                if(prev_sign == '+') st.push(cur);
                else if(prev_sign == '-') st.push(-1*cur);
                else {
                    int num = st.top(); st.pop();
                    if(prev_sign == '*') st.push(num*cur);
                    else if(prev_sign == '/') st.push(num/cur);
                }
                
                cur=0;
                prev_sign = ch;
            }
        }
        
        while(!st.empty()) ans += st.top(), st.pop();
        return ans;
    }
};