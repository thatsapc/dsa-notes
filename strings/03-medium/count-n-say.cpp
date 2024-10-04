#include<bits/stdc++.h>
using namespace std;

string countnsay(int n){
  if(n == 1){
    //cout << "n: " << 1 << "; cns:" << "1" << endl;
    return "1";
  }
  string prev = countnsay(n - 1);
  string ans;
  int head = 0, tail = head;
  int count = 0;
  while(tail < prev.size()){
    while(tail < prev.size() && prev[head] == prev[tail]){
      count++;
      tail++;
    }
    ans += to_string(count) + prev[head];
    count = 0;
    head = tail;
  }
  //cout << "n: " << n << "; cns:" << ans << endl;
  return ans;
}

int main(){
  int n = 7;
  cout << countnsay(n) << endl;
  return 0;
}