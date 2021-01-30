class Solution {
public:
    
    bool isSelfDiving(int n) {
        int k = n;
        while(n){
            int a = n%10;
            if(a == 0)
                return false;
            if(k%a != 0)
                return false;
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ar;
        for(int i=left; i <= right; i++) {
            if(isSelfDiving(i)) {
                ar.push_back(i);
            }
        }
        return ar;
    }
};