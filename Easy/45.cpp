class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        int parent = kthGrammar(N-1, K/2 + K%2);
        bool isKOdd = (K%2 == 1);
        
        if(parent == 1) return isKOdd;
        else return !isKOdd;
    }
}; 