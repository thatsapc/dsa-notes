#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr, int n){
  unordered_map<int, int> sumidx;
  int sum = 0;
  int maxlen = 0;
  for (int i = 0; i < n; i++){
    sum += arr[i];
    if(sum == 0){
      maxlen = max(i + 1, maxlen);
    }
    else if(sumidx.count(sum) != 0){
      maxlen = max(i - sumidx[sum], maxlen);
    }
    else{
      sumidx[sum] = i;
    }
  }
  return maxlen;
}

int main(){
  vector<int> arr = {1, 0, -4, 3, 1, 0};
  int n = arr.size();
  cout << maxLen(arr, n) << endl;
  return 0;
}