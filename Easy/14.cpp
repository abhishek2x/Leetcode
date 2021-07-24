class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> v(10000, 0);
        multiset<int> st;
        
        for(int a: arr) 
            v[a+1000]++;
        
        for(int a: v) 
            if(a)
                st.insert(a);
        
        for(int a: st) 
            cout << a << " ";
        
        for(int a: st) 
            if(st.count(a) > 1) return false;
        
        
        return true;
    }
};
