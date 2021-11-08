/*

Runtime Error Message:
Line 23: Char 28: runtime error: signed integer overflow: 498828660196 * 840477629533 cannot be represented in type 'long long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:32:28
Last executed input:
"498828660196"
"840477629533"

*/


class Solution {
public:
    
    long long converToInt(string s) {
        long long lst=0;
        long long b=0;
        char a;
        
        while(lst<s.length()) {
            a = s[lst];
            b = (b * 10) + (int)(a-'0');
            lst++;
        }
        return b;
    }
    
    string multiply(string num1, string num2) {
        long long n1, n2;
        
        n1 = converToInt(num1);
        n2 = converToInt(num2);
        
        return to_string(n1*n2);
    }
};