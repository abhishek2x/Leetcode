class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = (current[0] - '0')*10 + current[1] - '0';
        int m1 = (current[3] - '0')*10 + current[4] - '0';
        
        int h2 = (correct[0] - '0')*10 + correct[1] - '0';
        int m2 = (correct[3] - '0')*10 + correct[4] - '0';
        
        m1 += h1*60;
        m2 += h2*60;
        int res=0;
                
        if (m2 - m1 >= 60) res += (m2 - m1)/60, m1 += ((m2 - m1)/60) * 60;

        if (m2 - m1 >= 15) res += (m2 - m1)/15, m1 += ((m2 - m1)/15) * 15;
        
        if ((m2 - m1) >= 5) res += (m2 - m1)/5, m1 += ((m2 - m1)/5) * 5;
        
        res += (m2 - m1);
        
        return res;
    }
};


// "02:30"
// "04:35"
// "11:00"
// "11:01"
// "09:41"
// "10:34"
// "10:50"
// "11:20"