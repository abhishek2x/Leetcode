/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getAns(int n, int k) {
  if(n == 1)  return 1;
  if(k <= 2) return k-1;
  
  return getAns(n-1, ceil(k/2));
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  cout << getAns(4, 3);
  cout << getAns(4, 4);
  cout << getAns(4, 5);

  return 0;
}