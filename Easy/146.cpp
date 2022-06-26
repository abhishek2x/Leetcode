class Solution {
public:
    
    static bool comp(string s1, string s2) {
        string l1 = s1.substr(s1.find(' '));
        string l2 = s2.substr(s2.find(' '));
        
        if(l1 != l2) return l1 < l2;
        else return s1 < s2;
        
    }
    
    bool isLetterLog(string log) {
        char ch = log[log.size()-1];
        return isalpha(ch);
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