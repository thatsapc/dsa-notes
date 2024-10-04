#include<bits/stdc++.h>
using namespace std;

vector<long long> pascal(int n){
  if(n == 1){
    return {1};
  }
  if(n == 2){
    return {1, 1};
  }
  vector<long long> ans(n, 0);
  ans[0] = 1;
  ans[n - 1] = 1;
  vector<long long> prev = pascal(n - 1);
  for (int i = 1; i < n - 1; i++){
    ans[i] = prev[i] + prev[i - 1];
  }
  return ans;
}

int main(){
  int n = 4;
  vector<long long> row = pascal(n);
  for(auto r : row){
    cout << r << " ";
  }
  cout << endl;
  return 0;
}