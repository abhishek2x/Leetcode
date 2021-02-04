class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() == 1) {
            return 0;
        }
        int minm=INT_MAX;
        int maxm=INT_MIN;
        
        for(int i=0; i<A.size(); i++) {
            minm = min(minm, A[i]);
            maxm = max(maxm, A[i]);
        }
        
        if(maxm-minm > 2*K){
            return maxm-minm - 2*K;
        } else return 0;
    }
};