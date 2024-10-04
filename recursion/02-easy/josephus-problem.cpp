#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int safe(int n, int k){
  if(n == 1){
    //cout << "people:" << n << "; safe at: " << 1 << endl;
    return 1;
  }
  int prevSafe = safe(n - 1, k);
  int safe = (prevSafe + k) % n;
  safe = (safe == 0) ? n : safe;
  //cout << "people:" << n << "; safe at: " << safe << endl;
  return safe;
}

int main(){
  int n = 5;
  int k = 3;
  cout << safe(n, k) << endl;
  return 0;
}