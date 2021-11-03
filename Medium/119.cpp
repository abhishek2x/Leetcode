class Solution {
public:
    
    static bool comparator(pair<char, int>& p1, pair<char, int>& p2) {
        
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<pair<char, int>> v;
        string res;
        
        for(char c:s) freq[c]++;
        
        for(auto it:freq) {
            v.push_back({it.first, it.second});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        for(auto it: v) {
            while(it.second--)
                res += it.first;
        }
        return res;
    }
};

// "tree"
// "cccaaa"
// "Aabb"
// "raaeaedere"
