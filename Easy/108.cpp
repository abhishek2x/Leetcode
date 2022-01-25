class Solution {
public:
    
    static int ones(int num) {
        int f=0;
        while(num) {
            if(1 & num) f++;
            num = num >> 1;
        }
        return f;
    }
    
    static bool comp(int i, int j) {
        int p = ones(i);
        int q = ones(j);
        
        if(p == q) return i<j;
        else return p <= q;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};