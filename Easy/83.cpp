/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int value;
    unordered_map<int, pair<int, vector<int>> > mp;
    
    void init(vector<Employee*> employees) {
        value=0;
        for(auto it: employees){
            mp[it->id].first = it->importance;
            for(int child: it->subordinates) 
                mp[it->id].second.push_back(child);
        }
    }
    
    void helper(int id) {
        value += mp[id].first;
        for(int child: mp[id].second) {
            helper(child);   
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        init(employees);
        helper(id);
        return value;
    }
};