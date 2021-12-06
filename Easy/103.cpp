class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e=0, o=0;
        for(int ele: position) {
            if(ele%2) o++;
            else e++;
        }
        
        return o<e ? o : e;
    }
};