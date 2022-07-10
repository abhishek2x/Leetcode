class Solution {
public:
    int climbStairs(int n) {
        int step1 = 1;
        int step2 = 1;
        int res=0;
        
        
        for(int i=2; i<n+1; i++) {
            res = step1;
            res += step2;
            
            step2 = step1;
            step1 = res;
        }
        return step1;
    }
};