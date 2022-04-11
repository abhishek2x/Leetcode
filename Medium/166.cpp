class Solution {
public:
    
    int timeRequired(vector<int>& piles, int k) {
        int res=0;
        for(int i: piles) res += ceil(1.0*i / k);
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, res = INT_MIN;
        for(int ele: piles) res = max(res, ele);
        int high = res;
        
        while(low <= high) {
            int k = (low+high)/2;
            if(timeRequired(piles, k) <= h) 
                res = min(res, k), high = k-1;
            else low = k+1;
        }
        return res;
    }
};