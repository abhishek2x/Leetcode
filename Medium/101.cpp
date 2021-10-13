class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        if(!(r-l)) return r;
        
        int lg = (int) log2(r-l);
        
        lg++;
        l &= r;
        l >>= lg;
        l <<= lg;
        
        return l;
    }
};
