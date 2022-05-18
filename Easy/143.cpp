class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int size = v.size();
        
        vector<int> temp(size);
        k = k % size;
        int j=0;
        
        for(int i=size-(k); i < size; i++)
            temp[j++] = v[i];
        
        for(int i=0; i< size-k; i++) 
            temp[j++] = v[i];
        
        for(int i=0; i<size; i++)
            v[i] = temp[i];
        
    }
};
