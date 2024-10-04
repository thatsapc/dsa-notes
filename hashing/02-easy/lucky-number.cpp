#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool isLucky(long long N){
  unordered_set<long long> dgprod;
  vector<int> digits;
  while(N > 0){
    digits.push_back(N % 10);
    N = N / 10;
  }
  for (int i = digits.size() - 1; i >= 0; i--){
    int prod = 1;
    for (int j = i; j >= 0; j--){
      prod *= digits[j];
      if(dgprod.count(prod) == 0){
        dgprod.insert(prod);
      }
      else{
        return false;
      }
    }
  }
  return true;
}

int main(){
  long long N = 3261;
  cout << isLucky(N) << endl;
  return 0;
}