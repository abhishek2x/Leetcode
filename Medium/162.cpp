class Solution {
public:
    long long numberOfWays(string s) {
    
        long long res=0;
        vector<int> prez(size(s), 0), preo(size(s), 0);
        
        // This will take O(n)
        
        if(s[0] == '0') prez[0] = 1;
        else preo[0] = 1;
        
        for(int i=1; i<size(s); i++) {
            preo[i] += preo[i-1];
            prez[i] += prez[i-1];
                
            if(s[i] == '1') preo[i] += 1;
            else prez[i] += 1;
        }
        
        
        // This will take O(n)
        for(int i=1; i<size(s)-1; i++) {
            if(s[i] == '0') {
                // count left ones
                int lOnes = preo[i-1];
                // count right ones
                int rOnes = preo[size(s)-1] - preo[i];
                
                res += lOnes*rOnes;
            } else {
                // count left zeros
                int lZeros = prez[i-1];
                // count right zeros
                int rZeros = prez[size(s)-1] - prez[i];
                
                res += lZeros*rZeros;
            }
        }
        
        return res;
    }
};