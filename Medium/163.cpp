class Solution {
public:    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0, res=0;
        for(auto it: candies) sum += it;
        int l=0, h=sum/k;
        
        
        // LINEAR SEARCH
        
        // for(int m=l; m<=h; m++) {
        //     int mSum=0;
        //     for(auto it: candies) mSum += it/m;
        //     if(mSum >= k) res=m;
        // }
        
        // BINARY SEARCH
        while(l<h) {
            int m = (l+h+1)/2;
            
            long long mSum=0;
            for(auto it: candies) mSum += it/m;
            if(mSum >= k) {
                res=m;
                l=m;
            } else  h=m-1;
        }
        
        return res;
    }
};