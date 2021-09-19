#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
    int a[1000][1000];
    DetectSquares() {
        memset(a, 0, sizeof(a));
    }
    
    void add(vector<int> point) {
        a[point[0]][point[1]] += 1;
    }
    
    int count(vector<int> point) {
        // It doesn't add the new point
        int row = point[0]; 
        int col = point[1]; 

        int ans=0;

        // from 0 to col
        for(int i=0; i<1000; i++) {
            if(i == col) continue;
            if(a[row][i]) {
                int dis = abs(col-i);

                // bottom
                if(row+dis < 1000) 
                    if(a[row+dis][i] && a[row+dis][col]) 
                        ans += max({a[row+dis][i], a[row+dis][col], a[row][i], a[row][col]});

                // top
                if(row-dis >= 0) 
                    if(a[row-dis][i] && a[row-dis][col]) 
                        ans += max({a[row-dis][i], a[row-dis][col], a[row][i], a[row][col]});

            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */