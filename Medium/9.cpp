
class Solution {
public:
    bool judgeSquareSum(long c) {
        for(long i=0; i*i <= c; i++) {
            for(long j=0; j*j <= c; j++) {
                if(i*i + j*j == c) {
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool judgeSquareSum(long c) {
        for(long a=0; a*a <= c; a++) {
            double b = sqrt(c-a*a);
            if(b == (long)b) return true;
        }
        return false;
    }
};

class Solution {
public:
    
    bool checkPerf(long n) {
        long l=0;
        long h = n;
        while(l<=h) {
            long mid = (l + h)/2;
            if(mid*mid == n)
                return true;
            else if(mid*mid < n)
                l=mid+1;
            else h=mid-1;
        }
        return false;
    }
    
    bool judgeSquareSum(long c) {
        for(long a=0; a*a <= c; a++) {
            if(checkPerf(c-a*a)) return true;
        }
        return false;
    }
};