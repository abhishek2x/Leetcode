class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        int l=0, r = n.size()-1;
        
        while(l<r) {
            int m = (l+r)/2;
            if((m%2 == 0 and n[m] == n[m+1]) || (m%2 == 1 and n[m] == n[m-1])) {l = m+1;}
            else {r = m;}
        }
        return n[l];
    }
};



class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        int x = n[0];
        for(int i=1; i<n.size(); i++) x ^= n[i];
        return x;
    }
};

