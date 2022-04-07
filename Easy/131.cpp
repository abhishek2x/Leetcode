class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        
        for(auto it: stones) maxH.push(it);
        
        while(maxH.size() > 1) {
            int first = maxH.top(); maxH.pop();
            int second = maxH.top(); maxH.pop();
            
            if(first == second) continue;
            maxH.push(first-second);
        }
        
        return maxH.size() > 0 ? maxH.top() : 0;
    }
};