class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(string str: ops) {
            if(str == "+") {
                int first = st.top(); st.pop();
                int second = st.top(); st.push(first);
                st.push(first + second);
            }
            else if(str == "D") {
                int tp = st.top();
                st.push(tp*2);
            } else if(str == "C") {
                st.pop();
            } else {
                //convert str to int
                int number = stoi(str);
                st.push(number);
            }
        }
        
        int res = 0;
        // return sum of element in the stack
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};