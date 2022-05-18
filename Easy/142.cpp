class Solution {
public:
    int trailingZeroes(int n) {
        if(!n) return 0;
        int fc=0, tc=0;
        int m = n;
        
        while(n>=5)
        {
            fc+=n/5;
            n=n/5;
        }
        
        while(m>=2)
        {
            tc+=m/2;
            m=m/2;
        }
        
        return min(fc, tc);
    }
};

// 100!
    
// 5 | 100
// 5 | 20
// 5 | 4