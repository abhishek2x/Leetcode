class Solution {
public:
    int minCostToMoveChips(vector<int>& given) {
        vector<int> position(2, 0);
        for(auto i: given){
            position[i%2]++;
        }
        return min(position[0], position[1]);
    }
};