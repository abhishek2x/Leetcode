
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int csum = A[0];
        int osum = A[0];

        for(int i=1; i<A.size(); i++) {
            if(csum<0) {
                csum = A[i];
            } else {
                csum += A[i];
            }
            osum = max(osum, csum);
        }
        return osum;
    }
};