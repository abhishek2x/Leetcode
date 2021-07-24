/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int Kanping(vector<int>& values, vector<int>& weights, int n, int W) {
  // base
  if(n == 0 || W == 0)
    return 0;

  // choice 
  if(weights[n-1] > W){
    // not include
    return Kanping(values, weights, n-1, W);
  } else {
    // include or not include
    return max( weights[n-1] + Kanping(values, weights, n-1, W-weights[n-1]), Kanping(values, weights, n-1, W));
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  vector<int> values = {60, 100 ,120};
  vector<int> weights = {10, 20, 30};
  int W = 50;

  cout << Kanping(values, weights, 3, W);
  return 0;
}