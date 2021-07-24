class Solution {
public:
    int findKthPositive(vector<int>& st, int k) {
        int i=1, cnt=0, ans=0;
        
        while(true) {
            if(find(st.begin(), st.end(), i) == st.end()) {
                ans++;
                cout << "Ans: " << i << "\n";
            }
            if(ans == k) break;
            i++;
        }
        return i;
    }
};
