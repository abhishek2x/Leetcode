class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        
        while(n>0) {
            if(n-i>=0)
                n-=i;
            else break;
            i++;
        }
        return i-1;
    }
};