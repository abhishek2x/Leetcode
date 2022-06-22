class Solution {
public:
    
    static bool comp(string s1, string s2) {
        string f1="", l1="", f2="", l2="", k;
        int i=0;
        
        stringstream ss1(s1);
        while(ss1 >> k) {
            if(i == 0) f1 += k;
            else l1 += k + ' ';
            i++;
        }
        
        i = 0;
        
        stringstream ss2(s2);
        while(ss2 >> k) {
            if(i == 0) f2 += k;
            else l2 += k + ' ';
            i++;
        }
        
        if(l1 != l2) return l1 < l2;
        else return f1 < f2;
        
    }
    
    bool isLetterLog(string log) {
        stringstream ss(log);
        string k; int i=0;
        while(ss >> k) {
           if(i != 0 && !isdigit(k[0])) return true;
            i++;
        }
        return false;
    }
    
    void pushVec(vector<string>& res, vector<string>& v) {
        for(auto it: v) res.push_back(it);
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, letterLog, digitLog;
        
        for(string str: logs) {
            if(isLetterLog(str)) letterLog.push_back(str);
            else digitLog.push_back(str);
        }
        
        sort(letterLog.begin(), letterLog.end(), comp);
        
        
        pushVec(res, letterLog);
        pushVec(res, digitLog);
        
        return res;
    }
};


// ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
// ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
// ["t kvr", "r 3 1", "i 403", "7 so", "t 54"]
// ["j mo", "5 m w", "g 07", "o 2 0", "t q h"]