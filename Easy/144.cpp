class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int size = v.size();
        k = k % size;
        
        reverse(begin(v), end(v));
        reverse(begin(v), begin(v)+k);
        reverse(begin(v)+k, end(v));
    }
};
