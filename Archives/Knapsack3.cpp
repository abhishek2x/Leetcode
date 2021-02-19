/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int t[101][1001];


int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(t, -1, sizeof(t));
  
  vector<int> values = {60, 100 ,120};
  vector<int> weights = {10, 20, 30};
  int W = 50;

  cout << Kanping(values, weights, 3, W);
  return 0;
}
