/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int start = 0, end = n;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            int ans = guess(mid);
            
            if(ans == 0) return mid;
            if(ans == 1) start = mid+1;
            else end = mid;
        }
        return 0;
    }
};