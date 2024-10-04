#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string str, int k){
  int n = str.size();
  unordered_map<char, int> charf;
  int maxlen = -1;
  int head = 0;
  int tail = 0;
  while(tail < n){
    charf[str[tail]]++;
    while(charf.size() > k && head <= tail){
      charf[str[head]]--;
      if(charf[str[head]] == 0)
        charf.erase(str[head]);
      head++;
    }
    if(charf.size() == k){
      maxlen = max(tail - head + 1, maxlen);
    }
    tail++;
  }
  return maxlen;
}

int main(){
  int k = 1;
  string str = "abcde";
  cout << longestKSubstr(str, k) << endl;
  return 0;
}