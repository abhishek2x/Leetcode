/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  vector<int> v = {1, 4, 5, 10, 14};

  int index = 2;
  for(int i=0; i<v.size(); i++) {
    if(index < 0) index += v.size();
    cout << index << " - " << v[index] << "\n";
    index--;
  }

  return 0;
}