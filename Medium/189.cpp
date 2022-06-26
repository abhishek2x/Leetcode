class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        // game of pointers
        
        int maxRes=0, res=0;
        int i=k-1, j=cardPoints.size()-1;
        
        for(int p=0; p<k; p++) res+=cardPoints[p];
        maxRes = res;
        
        while(i>=0) {
            res -= cardPoints[i];
            res += cardPoints[j];
            maxRes = max(res, maxRes);
            
            i--;
            j--;
        }
        
        return maxRes;
    }
};