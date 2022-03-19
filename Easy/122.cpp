class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        long k=x,n=0;
        
        while(x) {
            n = n*10 + x%10;
            x /= 10;
        }
        
        return k==n;
    }
};