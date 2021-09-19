#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
    int a[1000][1000];
    DetectSquares() {
        memset(a, 0, sizeof(a));
    }
    
    void add(vector<int> point) {
        a[point[0]][point[1]] = 1;
    }
    
    int count(vector<int> point) {
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */