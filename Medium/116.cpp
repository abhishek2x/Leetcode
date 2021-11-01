class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int> maxH;
        maxH.push(a); maxH.push(b); maxH.push(c);
        
        int res = 0;
        while(1) {
            int x = maxH.top(); maxH.pop();
            int y = maxH.top(); maxH.pop();
            
            if(x <= 0 || y <= 0) break;
            
            res++;
            x--; y--;
            
            maxH.push(x); maxH.push(y);
        }
        
        return res;
    }
};